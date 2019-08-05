/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 23:13:15 by nivergne          #+#    #+#             */
/*   Updated: 2019/08/05 18:52:40 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# define ERR_ARG "Usage: ./fdf [File]"

# define ERR_PARSE_1 "error in init_struct (fail to open file)"
# define ERR_PARSE_2 "error in get_dimension (invalid input)"
# define ERR_PARSE_3 "error in get_dimension (invalid map size)"
# define ERR_PARSE_4 "error in allocate_map (malloc error)"
# define ERR_PARSE_5 "error in fill_map (invalid input)"
# define ERR_PARSE_6 "error in fill_map (invalid line size)"

# define ERR_MLX_1 "error in fdf (fail to establish connection with X-Server)"
# define ERR_MLX_2 "error in fdf (fail to create a window)"
# define ERR_MLX_3 "error in fdf (fail to create an image)"
# define ERR_MLX_4 "error in fdf (fail to update image)"

# define WIN_HEIGHT 2000
# define WIN_WIDTH 2000
# define IMG_HEIGHT 1000
# define IMG_WIDTH 1000
# define IMG_BITS (IMG_HEIGHT * IMG_WIDTH * 4)

# define ESCAPE 53
# define ESPACE 49
# define TABULATION 48

# define COLOR_WHITE 0xFFFFFFFF
# define COLOR_CYAN 0xFF00FFFF
# define COLOR_PURPLE 0xFFFF00FF
# define COLOR_GREEN 0xFF00FF00
# define COLOR_RED 0xFFFF0000

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
# define KEY_U 32
# define KEY_J 38

#endif
