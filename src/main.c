/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 23:59:35 by nivergne          #+#    #+#             */
/*   Updated: 2019/03/12 16:53:35 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	t_coord	m;
	// void		*mlx_ptr;
	// void		*window_ptr;

	// mlx_ptr = mlx_init();
	// window_ptr = mlx_new_window(mlx_ptr, HEIGHT, WIDTH, "fdf");
	// mlx_loop(mlx_ptr);
	if (init_struct(av[1], &m) == -1)
		return (-1);
	print_struct(&m);
	return (0);
}
