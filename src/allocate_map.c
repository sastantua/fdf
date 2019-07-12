/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 14:45:38 by nivergne          #+#    #+#             */
/*   Updated: 2019/07/12 17:56:54 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

int		allocate_map(t_map *m)
{
	int i;

	i = 0;
	if (!(m->map = (int **)ft_memalloc(sizeof(int *) * (m->y_max + 1))))
		return (error_msg(ERR_3));
	while (i < m->y_max)
	{
		if (!(m->map[i] = (int *)ft_memalloc(sizeof(int) * (m->x_max + 1))))
			return (error_msg(ERR_3));
		i++;
	}
	m->map[i] = NULL;
	return (0);
}