/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 14:17:48 by nivergne          #+#    #+#             */
/*   Updated: 2019/07/12 19:00:07 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				check_digit(char c)
{
	if ((c >= '0' && c <= '9') || c == '-')
		return (1);
	return (0);
}

int				parse_line(char *line)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (line[i])
	{
		while (check_digit(line[i]))
			i++;
		while (line[i] == ' ')
			i++;
		ret++;
	}
	return (ret);
}