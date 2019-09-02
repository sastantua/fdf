/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dimension.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 17:17:01 by nivergne          #+#    #+#             */
/*   Updated: 2019/08/29 22:01:05 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

int		get_dimension(t_fdf *f)
{
	f->x_max = 0;
	if (!(get_next_line(f->fd, &f->line) > 0))
		return (-1);
	f->y_max = 1;
	f->x_max = parse_line(f->line);
	ft_strdel(&f->line);
	while (get_next_line(f->fd, &f->line) != 0)
	{
		if (parse_line(f->line) == -1)
			return (gnl_error_free(&f->line, ERR_PARSE_2));
		ft_strdel(&f->line);
		f->y_max++;
	}
	ft_strdel(&f->line);
	if (f->x_max < 1 || f->y_max < 1)
		return (error_msg(ERR_PARSE_3));
	return (0);
}
