/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 16:03:00 by nivergne          #+#    #+#             */
/*   Updated: 2019/08/05 21:50:19 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>
#include <stdlib.h>

void	set_pixel_value(int x, int y, int color, t_fdf *f)
{
	int index;

	index = ((IMG_HEIGHT * y) + x) * 4;
	if (x > 0 && x < IMG_HEIGHT && y > 0 && y < IMG_WIDTH)
	{
		f->img[index] = color & 0xFF;
		f->img[index + 1] = (color >> 8) & 0xFF;
		f->img[index + 2] = (color >> 16) & 0xFF;
		f->img[index + 3] = (color >> 24) & 0x00;
	}
}

void	bresenham(int color, t_point *start, t_point *end, t_fdf *f)
{
	t_bresenham b;

	bresenham_init(start, end, &b);
	if (fabs(b.delta_y) < fabs(b.delta_x))
	{
		b.slope = b.delta_y / b.delta_x;
		b.pitch = start->y - b.slope * start->x;
		while ((int)round(start->x) != (int)round(end->x))
		{
			set_pixel_value((int)round(start->x), (int)lround((b.slope * start->x) + b.pitch), color, f);
			start->x += b.sign_x;
		}
	}
	else
	{
		b.slope = b.delta_x / b.delta_y;
		b.pitch = start->x - b.slope * start->y;
		while ((int)round(start->y) != (int)round(end->y))
		{
			set_pixel_value((int)lround((b.slope * start->y) + b.pitch), (int)round(start->y), color, f);
			start->y += b.sign_y;
		}
	}
}

/*
** ===================== bresenham ========================
** this function implement the bresenham algorithm
** comment if the implementation from code genius works cf
** https://www.youtube.com/watch?v=zytBpLlSHms&feature=youtu.be&t=245
*/

/*
** =================== set_pixel_value ====================
** 1. put index at image width (x_max size) * number of line
** 1b (y value) + number of pixel of the line already set (x value)
** 2. if the index is in the map
** ** 3. set the value of the pixel (4 bytes, opacity is ignored)
** ** 4. so color & 255 to put the right color on the pixel
** Info: we bzero earlier so if no color is set, it will be 0 0 0 0
** Info: and 0 0 0 0 is black, with no transparency
*/
