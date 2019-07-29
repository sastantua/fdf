/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 17:57:22 by nivergne          #+#    #+#             */
/*   Updated: 2019/07/29 17:53:34 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "ft_printf.h"

void	print_struct(t_fdf *f)
{
	int i;
	int j;

	i = 0;
	j = 0;
	ft_printf("fd = %d\n", f->fd);
	ft_printf("x_max = %d\n", f->x_max);
	ft_printf("y_max = %d\n", f->y_max);
	while (f->map[i] != NULL)
	{
		j = 0;
		ft_printf("line = %d\n", i);
		while (f->map[i][j] != -424242)
		{
			ft_printf("f->map[%d][%d] = %d\n", i, j, f->map[i][j]);
			j++;
		}
		i++;
	}
}
