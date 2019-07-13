/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 16:03:00 by nivergne          #+#    #+#             */
/*   Updated: 2019/07/13 16:03:26 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

int		bresenham(int x_start, int y_start, int x_end, int y_end)
{
	t_bresenham b;

	b.delta_x = x_end - x_start;
	b.delta_y = y_end - y_start;
	if (b.delta_x == 0 && b.delta_y == 0)
		return (draw(x_start, y_start));
	(b.delta_x >= 0) ? (b.sign_x = 1) : (b.sign_y = -1);
	(b.delta_x >= 0) ? (b.sign_x = 1) : (b.sign_y = -1);
	if (abs(b.delta_y) < abs(b.delta_x))
	{
		b.slope = b.delta_y / b.delta_x;
		b.pitch = y_start - b.slope * x_start;
		while (x_start != x_end)
		{
			draw(x_start, (int)(b.slope * x_start + b.pitch));
			x_start += b.sign_x;
		}
	}
	else
	{
		b.slope = b.delta_x / b.delta_y;
		b.pitch = x_start - b.slope * y_start;
		while (y_start != y_end)
		{
			draw(x_start, (int)(b.slope * y_start + b.pitch));
			x_start += b.sign_x;
		}
	}
	draw(x_end, y_end);
}