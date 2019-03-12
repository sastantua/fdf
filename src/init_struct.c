/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 07:56:19 by nivergne          #+#    #+#             */
/*   Updated: 2019/03/12 16:46:43 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		init_struct(char *file_name, t_coord *m)
{
	if (init_fd(file_name, m) == -1)
		return (-1);
	if (init_xmax(file_name, m) == -1)
		return (-1);
	if (init_ymax(file_name, m) == -1)
		return (-1);
	if (init_coord(file_name, m) == -1)
		return (-1);
	return (0);
}

void	print_struct(t_coord *m)
{
	int i;

	i = 0;
	ft_printf("fd = %d\n", m->fd);
	ft_printf("x_max = %d\n", m->x_max);
	ft_printf("y_max = %d\n", m->y_max);
	while (m->coord[i++])
		ft_printf("coord[%d] = %d\n", i, m->coord[i]);
}
