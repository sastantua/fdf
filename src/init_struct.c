/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 07:56:19 by nivergne          #+#    #+#             */
/*   Updated: 2019/07/12 17:57:58 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		init_struct(char *file_name, t_map *m)
{
	if (init_fd(file_name, m) == -1)
		return (-1);
	if (get_dimension(m) == -1)
		return (-1);
	if (allocate_map(m) == -1)
		return (-1);
	close(m->fd);
	if (init_fd(file_name, m) == -1)
		return (-1);
	if (fill_map(m) == -1)
		return (-1);
	return (0);
}
