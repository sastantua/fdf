/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 07:50:30 by nivergne          #+#    #+#             */
/*   Updated: 2019/03/12 16:34:08 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

int		check_digit(char c)
{
	if ((c >= '0' && c <= '9') || c == '-')
		return (1);
	return (0);
}

int		check_map(char c)
{
	if ((c >= '0' && c <= '9') || c == '-' || c == ' ' || c == '\n' || c == '\0')
		return (1);
	return (0);
}

int		check_map2(char c)
{
	if ((c >= '0' && c <= '9') || c == '-' || c == ' ' || c == '\n')
		return (1);
	return (0);
}
