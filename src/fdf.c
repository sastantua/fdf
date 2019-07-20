/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 23:57:58 by nivergne          #+#    #+#             */
/*   Updated: 2019/07/20 22:29:08 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "libft.h"

void	draw_link_x(int x, int y, t_fdf *f)
{
	int color;
	t_point start;
	t_point end;

	color = 0xFFFFFFFF;
	if (x + 1 < f->x_max)
	{
		if (f->map[y][x] > 0 && f->map[y][x + 1] > 0)
			color = 0x00FF0000;
		start = coord_init(x, y, f->map[y][x], f);
		end = coord_init(x + 1, y, f->map[y][x + 1], f);
		bresenham(color, &start, &end, f);
	}
}

void	draw_link_y(int x, int y, t_fdf *f)
{
	int color;
	t_point start;
	t_point end;

	color = 0xFFFFFFFF;
	if (y + 1 < f->y_max)
	{
		if (f->map[y][x] > 0 && f->map[y + 1][x] > 0)
			color = 0x00FF0000;
		start = coord_init(x, y, f->map[y][x], f);
		end = coord_init(x, y + 1, f->map[y + 1][x], f);
		bresenham(color, &start, &end, f);
	}
}

int	draw_map_iterate(t_fdf *f)
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

int		fdf(t_fdf *f)
{
	t_param p;

	fdf_init(f, &p);
	if (!(f->mlx_ptr = mlx_init()))
		return (error_msg(ERR_MLX_1));
	if (!(f->win_ptr = mlx_new_window(f->mlx_ptr, WIN_HEIGHT, WIN_WIDTH, "fdf")))
		return (error_msg(ERR_MLX_2));
	if (!(f->img_ptr = mlx_new_image(f->mlx_ptr, IMG_HEIGHT, IMG_WIDTH)))
		return (error_msg(ERR_MLX_3));
	if (!(f->img = mlx_get_data_addr(f->img_ptr, &p.pixel, &p.line, &p.endian)))
		return (error_msg(ERR_MLX_4));
	// mlx_hook(f->win_ptr, 2, 0, event_handler, f);
	draw_map_iterate(f);
	mlx_loop(f->mlx_ptr);
	return (0);
}

/* ========================= fdf ==========================
** 1. initialize the mlx with mlx_init
** 2. create a window and return a pointer to it
** 3. create an image and return a pointer to it
** 4. call mlx_hook to handle events
** 5. call mlx_loop to maintain display
** 6. call a function to iterate on each point of the map
*/

/* =================== draw_map_iterate ===================
** 1. initliaze an image with bzero
** 2. iterate through the map
** 3. on each point, call draw_link x and y
*/

/* ====================== draw_link =======================
** 1. check if the next point is still on the map
** ** 2. change the color to red
** ** 3. call bresenham function
*/

/* ===================== pseudo code ======================
** Je parse
** Je crée des pointeurs sur mlx_init, mlx_new_window et mlw_new_image
** Je parcours la map que je stock au cours du parsing
** Si la valeur du point courant et du point suivant x et x + 1 ou y et y + 1 sont toutes deux > 0
** Je set leur couleur et leur valeur puis je rentre dans bresenham
*/