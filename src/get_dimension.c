/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dimension.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 17:17:01 by nivergne          #+#    #+#             */
/*   Updated: 2019/07/12 18:55:00 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

int		get_dimension(t_map *m)
{
	int i;

	i = 0;
	m->x_max = 0;
	if (!(get_next_line(m->fd, &m->line) > 0))
		return (-1);
	m->y_max = 1;
	m->x_max = parse_line(m->line);
	while (get_next_line(m->fd, &m->line) > 0)
	{
		if (parse_line(m->line) == -1)
			return (gnl_error_free(&m->line, ERR_1));
		m->y_max++;
	}
	ft_strdel(&m->line);
	if (m->x_max < 1 || m->y_max < 1)
		return (error_msg(ERR_2));
	return (0);
}