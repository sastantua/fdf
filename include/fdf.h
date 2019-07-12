/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 23:13:15 by nivergne          #+#    #+#             */
/*   Updated: 2019/07/12 18:45:00 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define ERR_1 "error in get_dimension (invalid input)"
# define ERR_2 "error in get_dimension (invalid map size)"
# define ERR_3 "error in allocate_map (malloc error)"
# define ERR_4 "error in fill_map (invalid input)"
# define ERR_5 "error in fill_map (invalid line size)"

# define HEIGHT 1500
# define WIDTH 1000


typedef struct				s_map
{
	int		fd;
	int		x_max;
	int		y_max;
	int		**map;
	char	*line;
}							t_map;

//main.c
int				main(int ac, char **av);

//init_struct.c
int				init_struct(char *file_name, t_map *m);
void			print_struct(t_map *m);

//init_fd.c
int				init_fd(char *file_name, t_map *m);

//get_dimension.c
int				get_dimension(t_map *m);

//parse_line.c
int				check_digit(char c);
int				parse_line(char *line);

//allocate_map.c
int				allocate_map(t_map *m);

//fill_map.c
static	void	take_line(int y, char *line, t_map *m);
int				fill_map(t_map *m);

//error.c
int				error_msg(char *error_msg);
int				gnl_error_free(char **line, char *error_msg);

//debug.c
void			print_struct(t_map *m);


#endif
