/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 23:57:58 by nivergne          #+#    #+#             */
/*   Updated: 2019/07/13 16:05:03 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

int		fdf(t_fdf *f)
{
	if (!(f->mlx_ptr = mlx_init()))
		return (error_msg(ERR_MLX_1));
	f->win_ptr = mlx_new_window(f->mlx_ptr, HEIGHT, WIDTH, "fdf");
	mlx_loop(f->mlx_ptr);
}
