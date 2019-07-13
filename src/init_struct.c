/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 07:56:19 by nivergne          #+#    #+#             */
/*   Updated: 2019/07/13 13:33:53 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <unistd.h>

/* ================= init_struct ===================
** Open the map file
** Use gnl over the file to get the dimension
** Allocate the map in a int ** according to the map dimension
** Close the file cause lseek is forbidden
** Open back the file with read head at the begining
** Read lines and put the coordinates found in the int **
*/

int		init_struct(char *file_name, t_fdf *f)
{
	if (init_fd(file_name, f) == -1)
		return (-1);
	if (get_dimension(f) == -1)
		return (-1);
	if (allocate_map(f) == -1)
		return (-1);
	close(f->fd);
	if (init_fd(file_name, f) == -1)
		return (-1);
	if (fill_map(f) == -1)
		return (-1);
	return (0);
}
