/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:57:26 by mvicente          #+#    #+#             */
/*   Updated: 2023/08/29 19:41:57 by mvicente         ###   ########.fr       */
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
# define WINDOW_HEIGHT 600
# define ESCAPE 65307
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100

# define INF 1000000
# define PI 3.141592654
# define STEP 0.1

// ERROR MESSAGES

# define OPEN_ERROR "File not found or permission denied."
# define DIR_ERROR "File path is a directory"
# define MLC_ERROR "Allocation problem."
# define INVALID_ARGS "The program should take 1 argument."
# define INVALID_EXTENSION "Invalid file extension. File must be a .cub file."
# define INVALID_ARGS "The program should take 1 argument."
# define INVALID_MAP "Invalid map."
# define INVALID_ELEMENT "Invalid element in file."

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

typedef struct s_data
{
	void	*mlx;
	void	*win;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	distance;
	double	height;
	char	letter;
	char	*error;
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
	t_point	p;
	t_img	img;
	t_wall	wall[4];
}	t_data;

// FUNCTIONS

/* Parsing & Check */

void	parse_all(t_data *data, int argc, char *file_path);
void	error_msg(t_data *data, char *message);
char	*next_line(char *line, int fd);
int		is_only_spaces(char *line);

/* Check */

void	check_extension(t_data *data, char *path);
void	check_map(t_data *data);
void	check_texture_rgb(t_data *data, char *line);
void	check_rgb(t_data *data, char **splitted, char *line);
void	check_texture(t_data *data, char **splitted, char *line);

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