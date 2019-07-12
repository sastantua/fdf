/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 17:57:22 by nivergne          #+#    #+#             */
/*   Updated: 2019/07/12 18:47:14 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "ft_printf.h"

void	print_struct(t_map *m)
{
	int i;
	int j;

	i = 0;
	j = 0;
	ft_printf("fd = %d\n", m->fd);
	ft_printf("x_max = %d\n", m->x_max);
	ft_printf("y_max = %d\n", m->y_max);
	while (m->map[i] != NULL)
	{
		j = 0;
		ft_printf("line = %d\n", i);
		while (m->map[i][j] != -424242)
		{
			ft_printf("m->map[%d][%d] = %d\n", i, j, m->map[i][j]);
			j++;
		}
		i++;
	}
}
