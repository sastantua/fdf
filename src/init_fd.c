/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 07:56:19 by nivergne          #+#    #+#             */
/*   Updated: 2019/03/12 16:28:49 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "ft_printf.h"

int		init_fd(char *file_name, t_coord *m)
{
	if ((m->fd = open(file_name, O_RDONLY)) == -1)
		return (-1);
	return (0);
}
