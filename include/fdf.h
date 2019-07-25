/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 23:13:15 by nivergne          #+#    #+#             */
/*   Updated: 2019/07/25 08:20:36 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "ft_printf.h"

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

# define ESCAPE 53
# define ESPACE 49
# define TABULATION 48

# define ARROW_UP 126
# define ARROW_DOWN 125
# define ARROW_LEFT 123
# define ARROW_RIGHT 124

# define KEY_A 12
# define KEY_Q 0
# define KEY_Z 13
# define KEY_S 1
# define KEY_E 14
# define KEY_D 2
# define KEY_R 15
# define KEY_F 3
# define KEY_T 17
# define KEY_G 5
# define KEY_Y 16
# define KEY_H 4

# define COLOR_WHITE 0xFFFFFFFF
# define COLOR_CYAN 0xFF00FFFF
# define COLOR_PURPLE 0xFFFF00FF
# define COLOR_GREEN 0xFF00FF00
# define COLOR_RED 0xFFFF0000

typedef struct				s_fdf
{
	int				fd;
	char			*line;
	char			*img;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	int				pix;
	int				lin;
	int				end;
	int				x_max;
	int				y_max;
	int				**map;
	int				zoom;
	int				move_x;
	int				move_y;
	double			rotation_x;
	double			rotation_y;
	double			rotation_z;
	double			distortion_z;
	int				projection_type;
	unsigned int	color_grid;
	unsigned int	color_shape;
	int				exit_code;
}							t_fdf;

typedef struct 				s_bresenham
{
	int				sign_x;
	int				sign_y;
	double			delta_x;
	double			delta_y;
	double			slope;
	double			pitch;
}							t_bresenham;

typedef struct 				s_point
{
	double			x;
	double			y;
	double			z;
}							t_point;

//main.c
int					main(int ac, char **av);

//error.c
int					error_msg(char *error_msg);
int					gnl_error_free(char **line, char *error_msg);

//free_end.c
int					free_tab(int ***tab);
int					clean_exit(t_fdf *f);

//init_struct.c
int					init_struct(char *file_name, t_fdf *f);
void				print_struct(t_fdf *f);

//init_fd.c
int					init_fd(char *file_name, t_fdf *f);

//get_dimension.c
int					get_dimension(t_fdf *f);

//parse_line.c
int					check_digit(char c);
int					parse_line(char *line);

//allocate_map.c
int					allocate_map(t_fdf *f);

//fill_map.c
int					custom_atoi(char *line);
void				take_line(int y, char *line, t_fdf *f);
int					fill_map(t_fdf *f);

//fdf.c
void				draw_link_x(int x, int y, t_fdf *f);
void				draw_link_y(int x, int y, t_fdf *f); 
int					draw_map_iterate(t_fdf *f);
int					fdf(t_fdf *f);

//fdf_init.c
void				fdf_init(t_fdf *f);
t_point				coord_init(int x, int y, int z, t_fdf *f);
void				bresenham_init(t_point *start, t_point *end, t_bresenham *b);

//bresenham.c
void				set_pixel_value(int x, int y, int color, t_fdf *f);
void				bresenham(int color, t_point *start, t_point *end, t_fdf *f);

//event_handler.c
int					event_handler(int event, t_fdf *f);

//debug.c
void				print_struct(t_fdf *f);

#endif
