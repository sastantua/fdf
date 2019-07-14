/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 23:57:58 by nivergne          #+#    #+#             */
/*   Updated: 2019/07/14 22:12:43 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "libft.h"

/* =========== draw_link function ============
** 1. check if the next point is still on the map
** ** 2. change the color to red
** ** 3. call bresenham function
*/

void	draw_link_x(int x, int y, t_fdf *f)
{
	int color;

	color = 0xFFFFFF;
	if (x + 1 < f->x_max)
	{
		if (f->map[y][x] > 0 && f->map[y][x + 1] > 0)
			color = 0xFF0000;
		bresenham();
	}
}

void	draw_link_y(int x, int y, t_fdf *f)
{
	int color;

	color = 0xFFFFFF;
	if (y + 1 < f->y_max)
	{
		if (f->map[y][x] > 0 && f->map[y + 1][x] > 0)
			color = 0xFF0000;
		bresenham();
	}	
}

/* =========== draw_map_iterate function ============
** 1. initliaze an image with bzero
** 2. iterate through the map
** 3. on each point, call draw_link x and y
*/


int		draw_map_iterate(t_fdf *f)
{
	int y;
	int x;

	y = 0;
	ft_bzero(f->img, IMG_BITS);
	while (y < f->y_max)
	{
		x = 0;
		while (x < f->x_max)
		{
			draw_link_x(x, y, f);
			draw_link_y(x, y, f);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, f->img_ptr, 0, 0);
	return (0);
}

/* ================= fdf function ===================
** 1. initialize the mlx with mlx_init
** 2. create a window and return a pointer to it
** 3. create an image and return a pointer to it
** 4. call mlx_hook to handle events
** 5. call mlx_loop to maintain display
** 6. call a function to iterate on each point of the map
*/

int		fdf(t_fdf *f)
{
	if (!(f->mlx_ptr = mlx_init()))
		return (error_msg(ERR_MLX_1));
	if (!(f->win_ptr = mlx_new_window(f->mlx_ptr, WIN_HEIGHT, WIN_WIDTH, "fdf")))
		return (error_msg(ERR_MLX_2));
	if (!(f->win_ptr = mlx_new_image(f->mlx_ptr, IMG_HEIGHT, IMG_WIDTH)))
		return (error_msg(ERR_MLX_3));
	// mlx_hook(f->win_ptr, 2, 0, event_handler, ...);
	mlx_loop(f->mlx_ptr);
	draw_map_iterate(f);
	//order?
	return (0);
}
