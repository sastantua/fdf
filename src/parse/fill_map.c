/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 17:17:01 by nivergne          #+#    #+#             */
/*   Updated: 2019/08/29 22:07:49 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

int			custom_atoi(char *line)
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

void		take_line(int y, char *line, t_fdf *f)
{
	int x;
	int i;

	x = 0;
	i = 0;
	if (line)
	{
		while (line[i] && x < f->x_max)
		{
			f->map[y][x] = custom_atoi(line + i);
			while (line[i] && check_digit(line[i]))
				i++;
			while (line[i] && line[i] == ' ')
				i++;
			if (ft_strncmp(line + i, ",0xFFFFFF", 9) == 0)
			{
				f->map[y][x] = 255;
				i += 10;
			}
			x++;
		}
		f->map[y][x] = -424242;
	}
}

int			fill_map(t_fdf *f)
{
	int y;

	y = 0;
	while (get_next_line(f->fd, &f->line) >= 0 && y < f->y_max)
	{
		if (parse_line(f->line) == -1)
			return (gnl_error_free(&f->line, ERR_PARSE_5));
		if (y != 0 && parse_line(f->line) != f->x_max)
			return (gnl_error_free(&f->line, ERR_PARSE_6));
		take_line(y, f->line, f);
		ft_strdel(&f->line);
		y++;
	}
	if (f->line)
		ft_strdel(&f->line);
	return (0);
}
