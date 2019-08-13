/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 23:56:16 by nivergne          #+#    #+#             */
/*   Updated: 2019/08/05 19:15:02 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void		fdf_init(t_fdf *f)
{
	f->pix = 4;
	f->end = 0;
	f->lin = f->x_max;
	f->rotation_x = 0 - (10 * 3.14 / 180);
	f->rotation_y = 0;
	f->rotation_z = 0;
	f->distortion_z = 0.7;
	f->projection_type = 0;
	f->color_grid = COLOR_PURPLE;
	f->color_shape = COLOR_CYAN;
	f->zoom = (IMG_WIDTH / 2) / f->x_max;
	f->move_x = (IMG_WIDTH - (f->x_max * f->zoom)) / 2;
	f->move_y = (IMG_HEIGHT - (f->y_max * f->zoom)) / 2;
}

t_point		normal_init(int x, int y, int z, t_fdf *f)
{
	int		tmp;
	t_point	ret;

	x *= f->zoom;
	y *= f->zoom;
	z *= f->zoom * f->distortion_z;
	tmp = (x * cos(f->rotation_y)) + (ret.z * sin(f->rotation_y));
	ret.y = (y * cos(f->rotation_x)) + (z * sin(f->rotation_x));
	ret.z = (z * cos(f->rotation_x)) - (y * sin(f->rotation_x));
	ret.x = (x * cos(f->rotation_y)) + (ret.z * sin(f->rotation_y));
	ret.x = (ret.x * cos(f->rotation_z)) - (ret.y * sin(f->rotation_z));
	ret.y = (tmp * sin(f->rotation_z)) + (ret.y * cos(f->rotation_z));
	ret.x += f->move_x;
	ret.y += f->move_y;
	return (ret);
}

t_point		iso_init(int x, int y, int z, t_fdf *f)
{
	t_point	ret;

	x *= f->zoom;
	y *= f->zoom;
	z *= f->zoom * f->distortion_z;
	if (f->projection_type == 1)
	{
		ret.x = ((x - y) * cos(0.523599));
		ret.y = (-z + (x + y) * sin(0.523599));
	}
	else
	{
		ret.x = ((x - y) * cos(0.46373398));
		ret.y = (-z + (x + y) * sin(0.46373398));
	}
	ret.x += f->move_x;
	ret.y += f->move_y;
	return (ret);
}

t_point		coord_init(int x, int y, int z, t_fdf *f)
{
	if (f->projection_type == 0)
		return (normal_init(x, y, z, f));
	else
		return (iso_init(x, y, z, f));
}

void		bresenham_init(t_point *start, t_point *end, t_bresenham *b)
{
	b->delta_x = end->x - start->x;
	b->delta_y = end->y - start->y;
	b->sign_x = b->delta_x > 0 ? 1 : -1;
	b->sign_y = b->delta_y > 0 ? 1 : -1;
}
