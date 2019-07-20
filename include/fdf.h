/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 23:13:15 by nivergne          #+#    #+#             */
/*   Updated: 2019/07/19 17:24:50 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "ft_printf.h"

# define ERR_ARG "Usage: ./fdf [File]"

# define ERR_PARSE_1 "error in init_struct (fail to open file)"
# define ERR_PARSE_2 "error in get_dimension (invalid input)"
# define ERR_PARSE_3 "error in get_dimension (invalid map size)"
# define ERR_PARSE_4 "error in allocate_map (malloc error)"
# define ERR_PARSE_5 "error in fill_map (invalid input)"
# define ERR_PARSE_6 "error in fill_map (invalid line size)"

# define ERR_MLX_1 "error in fdf (fail to establish connection with the X-Server)"
# define ERR_MLX_2 "error in fdf (fail to create a window)"
# define ERR_MLX_3 "error in fdf (fail to create an image)"
# define ERR_MLX_4 "error in fdf (fail to update image)"

# define WIN_HEIGHT 1500
# define WIN_WIDTH 1000
# define IMG_HEIGHT 750
# define IMG_WIDTH 500
# define IMG_BITS (IMG_HEIGHT * IMG_WIDTH * 4)

typedef struct				s_fdf
{
	int			fd;
	char		*line;
	char		*img;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			x_max;
	int			y_max;
	int			**map;
	int			scale;
	int			point_pixel_x;
	int			point_pixel_y;
	int			distortion_z;
	int			exit_code;
}							t_fdf;

typedef struct 				s_bresenham
{
	int			delta_x;
	int			delta_y;
	int			sign_x;
	int			sign_y;
	double		slope;
	double		pitch;
}							t_bresenham;

typedef struct 				s_point
{
	double		x;
	double		y;
	double		z;
}							t_point;

typedef struct 				s_param
{
	int			pixel;
	int			line;
	int			endian;
}							t_param;

//main.c
int				main(int ac, char **av);

//error.c
int				error_msg(char *error_msg);
int				gnl_error_free(char **line, char *error_msg);

//free_end.c
int				free_tab(int ***tab);
int				clean_exit(t_fdf *f);

//init_struct.c
int				init_struct(char *file_name, t_fdf *f);
void			print_struct(t_fdf *f);

//init_fd.c
int				init_fd(char *file_name, t_fdf *f);

//get_dimension.c
int				get_dimension(t_fdf *f);

//parse_line.c
int				check_digit(char c);
int				parse_line(char *line);

//allocate_map.c
int				allocate_map(t_fdf *f);

//fill_map.c
// static	void	take_line(int y, char *line, t_fdf *f);
int				fill_map(t_fdf *f);

//fdf.c
// static void		draw_link_x(int x, int y, t_fdf *f);
// static void		draw_link_y(int x, int y, t_fdf *f);
// static int		draw_map_iterate(t_fdf *f);
int				fdf(t_fdf *f);

//fdf_init.c
void			fdf_init(t_fdf *f, t_param *p);
t_point			coord_init(int x, int y, int z, t_fdf *f);

//bresenham.c
void			set_pixel_value(int x, int y, int color, t_fdf *f);
void			bresenham(int color, t_point *start, t_point *end, t_fdf *f);

//debug.c
void			print_struct(t_fdf *f);

#endif
