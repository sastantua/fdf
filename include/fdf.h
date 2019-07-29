/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 23:13:15 by nivergne          #+#    #+#             */
/*   Updated: 2019/07/29 13:24:20 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "define.h"
# include "ft_printf.h"

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
