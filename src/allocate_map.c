/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 14:45:38 by nivergne          #+#    #+#             */
/*   Updated: 2019/07/20 14:03:40 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

int		allocate_map(t_fdf *f)
{
	int i;

	i = 0;
	if (!(f->map = (int **)ft_memalloc(sizeof(int *) * (f->y_max + 1))))
		return (error_msg(ERR_PARSE_4));
	while (i < f->y_max)
	{
		if (!(f->map[i] = (int *)ft_memalloc(sizeof(int) * (f->x_max + 1))))
			return (error_msg(ERR_PARSE_4));
		i++;
	}
	f->map[i] = NULL;
	return (0);
}