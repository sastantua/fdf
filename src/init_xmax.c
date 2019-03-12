/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_xmax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 07:56:19 by nivergne          #+#    #+#             */
/*   Updated: 2019/03/12 17:33:58 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		init_xmax(char *file_name, t_coord *m)
{
	int i;
	int ret;
	int res;

	i = 0;
	ret = 0;
	res = 0;
	if ((ret = get_one_line(m->fd, &m->line)) == 1)
	{
		m->x_len = ft_strlen(m->line);
		while (m->line[i])
		{
			if (check_digit(m->line[i]))
			{
				while (check_digit(m->line[i]))
					i++;
				res++;
			}
			i++;
		}
		// ft_printf("res = %d\n", res);
		m->x_max = res;
	}
	close(m->fd);
	ft_strdel(&m->line);
	return (0);
}
