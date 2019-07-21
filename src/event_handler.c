/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 22:24:38 by nivergne          #+#    #+#             */
/*   Updated: 2019/07/21 23:49:30 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

static void		move_handler(int event, t_fdf *f)
{
	if (event == ARROW_LEFT)
		f->move_x -= 10;
	else if (event == ARROW_RIGHT)
		f->move_x += 10;
	else if (event == ARROW_DOWN)
		f->move_y += 10;
	else if (event == ARROW_UP)
		f->move_y -= 10;
}

static void		rotate_handler(int event, t_fdf *f)
{
	if (event == A)
		f->rotation_x -= (10 * 3.14 / 180);
	else if (event == Q)
		f->rotation_x += (10 * 3.14 / 180);
	else if (event == Z)
		f->rotation_y -= (10 * 3.14 / 180);
	else if (event == S)
		f->rotation_y += (10 * 3.14 / 180);
	else if (event == E)
		f->rotation_z -= (10 * 3.14 / 180);
	else if (event == D)
		f->rotation_z += (10 * 3.14 / 180);
}

int				event_handler(int event, t_fdf *f)
{
	if (event == ESCAPE)
		return (clean_exit(f));
	else if (event == TABULATION)
	{
		if (f->projection_type == 0 || f->projection_type == 1)
			f->projection_type++;
		else
			f->projection_type = 0;
	}
	else if (event == ESPACE)
		fdf_init(f);
	else if (event == R)
		f->zoom++;
	else if (event == F)
		f->zoom--;
	//couleur - zmod - reset
	move_handler(event, f);
	rotate_handler(event, f);
	draw_map_iterate(f);
	ft_printf("event = %d\n", event);
	return (event);
}
