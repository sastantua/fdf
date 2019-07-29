/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 15:57:59 by nivergne          #+#    #+#             */
/*   Updated: 2019/07/25 19:24:57 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "libft.h"

int		free_tab(int ***map)
{
	int i;
	int **ptr;

	i = 0;
	ptr = NULL;
	if (!*map)
		return (0);
	ptr = *map;
	while ((*map)[i] != NULL)
	{
		free(ptr[i]);
		ptr[i] = NULL;
		i++;
	}
	ft_memdel((void *)map);
	return (1);
}

int		clean_exit(t_fdf *f)
{
	if (f->map)
		free_tab(&f->map);
	mlx_destroy_image(f->mlx_ptr, f->img_ptr);
	mlx_destroy_window(f->mlx_ptr, f->win_ptr);
	close(f->fd);
	if (f->exit_code == 1)
		exit(0);
	exit(-1);
}
