/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ymax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 07:56:19 by nivergne          #+#    #+#             */
/*   Updated: 2019/03/12 16:43:51 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		check_yline(t_coord *m)
{
	int i;
	int res;

	i = 0;
	res = 0;
	while (m->line[i])
	{
		if (check_digit(m->line[i]))
		{
			while (check_digit(m->line[i]))
				i++;
			res++;
		}
		else
			i++;
	}
	if (res != m->x_max)
		return (-1);
	return (0);
}

int		init_ymax(char *file_name, t_coord *m)
{
	int	i;
	int	ret;
		
	i = 0;
	ret = 0;
	if (init_fd(file_name, m) == -1)
		return (-1);
	while ((ret = get_next_line(m->fd, &m->line)) == 1)
	{
		if (check_yline(m) == -1)
			return (-1);
		i++;
	}
	m->y_max = i;
	close(m->fd);
	return (ret);
}
