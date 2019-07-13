/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 23:59:35 by nivergne          #+#    #+#             */
/*   Updated: 2019/07/13 16:04:59 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <unistd.h>

/* ================= main function ===================
** Create a mlx pointer, set window parameters and launch mlx loop
** Then initialize structure
*/

int		main(int ac, char **av)
{
	t_fdf	f;

	if (ac != 2)
		return (error_msg(ERR_ARG));
	if (init_struct(av[1], &f) == -1)
		return (-1);
	fdf();
	clean_exit(&f);
	return (0);
}
