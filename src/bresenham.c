/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 16:03:00 by nivergne          #+#    #+#             */
/*   Updated: 2019/07/19 17:30:26 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>
#include <stdlib.h>

void	set_pixel_value(int x, int y, int color, t_fdf *f)
{
	int index;

	index = ((IMG_WIDTH * y) + x) * 4;
	if (x > 0 && x < IMG_WIDTH && y > 0 && y < IMG_HEIGHT)
	{
		f->img[index] = color & 0xFF;
		f->img[index + 1] = (color >> 8) & 0xFF;
		f->img[index + 2] = (color >> 16) & 0xFF;
	}
}


void	bresenham(int color, t_point *start, t_point *end, t_fdf *f)
{
	t_bresenham b;

	b.delta_x = end->x - start->x;
	b.delta_y = end->y - start->y;
	// ft_printf("BEFORE\nb.delta_x = %d\nb.delta_y = %d\nb.sign_x = %d\nb.sign_y = %d\n", b.delta_x, b.delta_y, b.sign_x, b.sign_y);
	(b.delta_x >= 0) ? (b.sign_x = 1) : (b.sign_x = -1);
	(b.delta_y >= 0) ? (b.sign_y = 1) : (b.sign_y = -1);
	// ft_printf("AFTER\nb.delta_x = %d\nb.delta_y = %d\nb.sign_x = %d\nb.sign_y = %d\n", b.delta_x, b.delta_y, b.sign_x, b.sign_y);
	// ft_printf("1- in bresenham\n");
	if (b.delta_x == 0 && b.delta_y == 0)
	{
		// ft_printf("2- in bresenham\n");
		set_pixel_value(start->x, start->y, color, f);
	}
	else
	{
		// ft_printf("3- in bresenham\n");
		if (abs(b.delta_y) < abs(b.delta_x))
		{
			// ft_printf("4- in bresenham\n");
			b.slope = b.delta_y / b.delta_x;
			b.pitch = start->y - b.slope * start->x;
			while (start->x != end->x)
			{
				set_pixel_value(start->x, (int)(b.slope * start->x + b.pitch), color, f);
				start->x += b.sign_x;
			}
		}
		else
		{
			// ft_printf("5- in bresenham\n");
			b.slope = b.delta_x / b.delta_y;
			b.pitch = start->x - b.slope * start->y;
			while (start->y != end->y)
			{
				// ft_printf("6- in bresenham\n");
				// ft_printf("start->y = %d\nend->y = %d\nb.sign_y = %d\n", start->y, end->y, b.sign_y);
				set_pixel_value(start->x, (int)(b.slope * start->y + b.pitch), color, f);
				start->y += b.sign_y;
			}
		}
		set_pixel_value(end->x, end->y, color, f);
	}	
}

/* ===================== bresenham ========================
** this function implement the bresenham algorithm
** comment if the implementation from code genius works cf
** https://www.youtube.com/watch?v=zytBpLlSHms&feature=youtu.be&t=245 
*/

/* =================== set_pixel_value ====================
** 1. put index at image width (x_max size) * number of line
** 1b (y value) + number of pixel of the line already set (x value) 
** 2. if the index is in the map
** ** 3. set the value of the pixel (4 bytes, opacity is ignored)
** ** 4. so color & 255 to put the right color on the pixel
** Info: we bzero earlier so if no color is set, it will be 0 0 0 0
** Info: and 0 0 0 0 is black, with no transparency
*/
