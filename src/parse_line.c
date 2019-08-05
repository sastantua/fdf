/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 14:17:48 by nivergne          #+#    #+#             */
/*   Updated: 2019/08/05 19:17:58 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

int				check_digit(char c)
{
	if ((c >= '0' && c <= '9') || c == '-')
		return (1);
	return (0);
}

int				parse_line(char *line)
{
	int	i;
	int	j;
	int	ret;

	i = 0;
	j = 0;
	ret = 0;
	while (line[i])
	{
		if (j > 50)
			return (-1);
		while (line[i] && check_digit(line[i]))
			i++;
		while (line[i] && ft_strncmp(line + i, ",0xFFFFFF", 8) == 0)
			i += 10;
		while (line[i] && line[i] == ' ')
			i++;
		ret++;
		j++;
	}
	return (ret);
}
