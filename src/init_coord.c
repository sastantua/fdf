/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_coord.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 16:42:38 by nivergne          #+#    #+#             */
/*   Updated: 2019/03/12 18:07:38 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		init_coord(char *file_name, t_coord *m)
{
	int i;
	int j;
	int ret;

	i = 0;
	j = 0;
	ret = 0;
	if (init_fd(file_name, m) == -1)
		return (-1);
	if (!(m->coord = (int *)malloc(sizeof(int) * (m->x_max * m->y_max) + 1)))
		return (-1);
	while ((ret = get_next_line(m->fd, &m->line)) == 1)
	{
		while (m->line[i])
		{
			// ft_printf("line[i] = %c|\n", j, m->line[i]);
			if (check_digit(m->line[i]))
			{
				m->coord[j] = ft_atoi(&m->line[i]);
				// ft_printf("m->coord[%d] = %d\n", j, m->coord[j]);
				while (check_digit(m->line[i]))
					i++;
				j++;
			}
			i++;
		}
	}
	ft_strdel(&m->line);
	close(m->fd);
	return (0);
}
