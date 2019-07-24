/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 15:57:59 by nivergne          #+#    #+#             */
/*   Updated: 2019/07/24 02:09:27 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "libft.h"

int		free_tab(int ***tab)
{
	int i;

	i = 0;
	if (!*tab)
		return (0);
	while ((*tab)[i] != NULL)
	{
		free(&(*tab)[i]);
		(*tab)[i] = NULL;
		i++;
	}
	ft_memdel((void *)tab);
	return (1);
}

int		clean_exit(t_fdf *f)
{
	if (f->map)
		free_tab(&f->map);
	mlx_destroy_image(f->mlx_ptr, f->img_ptr);
	mlx_destroy_window(f->mlx_ptr, f->img_ptr);
	close(f->fd);
	if (f->exit_code == 1)
		return (0);
	return (-1);
}
