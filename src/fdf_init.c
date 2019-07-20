/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 23:56:16 by nivergne          #+#    #+#             */
/*   Updated: 2019/07/16 23:57:41 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void	fdf_init(t_fdf *f, t_param *p)
{
	p->pixel = 4;
	p->endian = 0;
	p->line = f->x_max;
	f->distortion_z = 0;
	f->scale = (IMG_WIDTH / 2) / f->x_max;
	f->point_pixel_x = (IMG_WIDTH - (f->x_max * f->scale)) / 2;
	f->point_pixel_y = (IMG_HEIGHT - (f->y_max * f->scale)) / 2;
}

t_point		coord_init(int x, int y, int z, t_fdf *f)
{
	t_point ret;

	x *= f->scale;
	y *= f->scale;
	z *= f->scale * f->distortion_z;
	ret.y = (y * cos(0)) + (z * sin(0));
	ret.z = (z * cos(0)) - (y * sin(0));
	ret.x = (x * cos(0)) + (ret.z * sin(0));
	x = ret.x;
	ret.x = (ret.x * cos(0)) - (ret.y * sin(0));
	ret.y = (x * sin(0)) + (ret.y * cos(0));
	ret.x += f->point_pixel_x;
	ret.y += f->point_pixel_y;
	return (ret);
}
