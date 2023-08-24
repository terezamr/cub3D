/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <rade-sar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:57:26 by mvicente          #+#    #+#             */
/*   Updated: 2023/08/24 11:05:01 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// INCLUDES

# include "./libft/libft.h"
# include "./minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include "math.h"

// DEFINES

# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 800
# define ESCAPE 65307
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100

# define WHITE_PIXEL 0xFFFFFF
# define BLACK_PIXEL 0x000000
# define GREY_PIXEL 0x808080
# define PINK_PIXEL 0xFFC0CB
# define PINK1_PIXEL 0xe5acb6
# define PINK2_PIXEL 0xcc99a2

# define INF 1000000
# define PI 3.141592654

// ERROR MESSAGES

# define OPEN_ERROR "File not found or permission denied."
# define DIR_ERROR "File path is a directory"
# define MLC_ERROR "Allocation problem."
# define PLAYER_ERROR "The map must have 1 player."
# define INVALID_ARGS "The program should take 1 argument."
# define INVALID_EXTENSION "Invalid file extension. File must be a .cub file."
# define INVALID_TEXTURE_TYPE "Type must be composed by one or two characters."
# define INVALID_TEXTURE "Texture file not found."
# define INVALID_RGB "Invalid RGB color."
# define INVALID_ARGS "The program should take 1 argument."
# define INVALID_MAP "Invalid map."
# define INVALID_BORDER "Invalid border."
# define INVALID_CHAR "Invalid character found."

// STRUCTS

typedef struct s_point
{
	int		x;
	int		y;
}	t_point;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_wall
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_wall;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	dir_x_init;
	double	dir_y_init;
	double	plane_x;
	double	plane_y;
	double	distance;
	double	height;
	char	letter;
	char	*file_path;
	char	**map;
	char	**textures;
	int		map_width;
	int		map_height;
	int		start;
	int		end;
	int		hit;
	int		step_x;
	int		step_y;
	int		side;
	int		*colors;
	int		*map_c;
	int		**world_map;
	t_point	p;
	t_img	img;
	t_wall	wall[4];
}	t_data;

// FUNCTIONS

/* Parsing & Check */

void	parse_all(t_data *data, int argc, char *file_path);
void	error_msg(char *message);
void	check_extension(char *path);
void	check_map(t_data *data);
char	*next_line(char *line, int fd);
int		is_only_spaces(char *line);
int		check_texture(t_data *data, char *line, int pos, int rgb);

/* Utils */

void	vars_init(t_data *data);
int		ft_isspace(int c);
int		is_only_spaces(char *line);

/* Events */

int		exit_cub(t_data *data);
int		handle_key(int key, t_data *data);

/* Moves */
void	move_w(t_data *data);
void	move_s(t_data *data);
void	move_d(t_data *data);
void	move_a(t_data *data);

/* Math */

void	calculations(t_data *data);
double	*get_dist(t_data *data, double *ray);

/* Picture */
void	drawing(int x, t_data *data, double *dist, double *ray);

/* Picture_aux */
int		get_rgb(int r, int g, int b);
void	ft_mlx_pixel_put(t_data *data, int x, int y, int color);
int		get_i(t_data *data, double *ray);

#endif