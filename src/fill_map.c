/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 17:17:01 by nivergne          #+#    #+#             */
/*   Updated: 2019/07/12 18:43:56 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

static	int	custom_atoi(char *line)
{
	int		i;
	int		sign;
	int		result;

	i = 0;
	sign = 1;
	result = 0;
	if (line[i] == '-')
		sign = -1;
	if (line[i] == '-')
		i++;
	while (line[i] >= '0' && line[i] <= '9')
	{
		result = result * 10 + line[i] - '0';
		i++;
	}
	return (result * sign);
}

static	void	take_line(int y, char *line, t_map *m)
{
	int x;
	int i;

	x = 0;
	i = 0;
	while (line[i])
	{
		m->map[y][x] = custom_atoi(line + i);
		while (line[i] && check_digit(line[i]))
			i++;
		if (line[i] == ' ')
			i++;
		x++;
	}
	m->map[y][x] = -424242;
}


int		fill_map(t_map *m)
{
	int y;

	y = 0;
	while (get_next_line(m->fd, &m->line) > 0)
	{
		if (parse_line(m->line) == -1)
			return (gnl_error_free(&m->line, ERR_4));
		if (y != 0 && parse_line(m->line) != m->x_max)
			return (gnl_error_free(&m->line, ERR_5));
		take_line(y, m->line, m);
		y++;
	}
	return (0);
}