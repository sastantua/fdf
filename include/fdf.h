/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 23:13:15 by nivergne          #+#    #+#             */
/*   Updated: 2019/03/12 16:43:38 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FDF_H_
# define _FDF_H_

# include "mlx.h"
# include "libft.h"
# include "ft_printf.h"


# define HEIGHT 1500
# define WIDTH 1000

typedef struct				s_struct
{
	int		fd;
	int		x_len;
	int		x_max;
	int		y_max;
	int		*coord;
	char	*line;
}							t_coord;

//main.c

//check_map.c
int		check_digit(char c);
int		check_map(char c);
int		check_map2(char c);

//init_struct.c
int		init_struct(char *file_name, t_coord *m);
void	print_struct(t_coord *m);

//init_fd.c
int		init_fd(char *file_name, t_coord *m);

//init_xmax.c
int		init_xmax(char *file_name, t_coord *m);

//init_ymax.c
int		init_ymax(char *file_name, t_coord *m);
int		init_coord(char *file_name, t_coord *m);

//init_coord.c

#endif
