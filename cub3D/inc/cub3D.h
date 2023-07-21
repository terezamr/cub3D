/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:57:26 by mvicente          #+#    #+#             */
/*   Updated: 2023/07/06 16:20:37 by mvicente         ###   ########.fr       */
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
#define PI 3.141592654

// ERROR MESSAGES

# define OPEN_ERROR "File not found or permission denied."
# define DIR_ERROR "File path is a directory"
# define MLC_ERROR "Allocation problem."
# define PLAYER_ERROR "The map must have 1 player."
# define INVALID_ARGS "The program should take 1 argument."
# define INVALID_EXTENSION "Invalid file extension. File must be a .cub file."
# define INVALID_TEXTURE_TYPE "Texture type must be composed by one or two characters."
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
	float	offset_r;
	float	offset_i;
}	t_img;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_img	img;
	double	posX;
	double	posY;
	char	letter;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
	char	*file_path;
	char	**map;
	int		map_width;
	int		map_height;
	int		**world_map;
	double	distance;
	double	height;
	int		start;
	int		end;
	int		hit;
	int		step_x;
	int		step_y;
	int		side;
	t_point	p;
	char	*nTexture;
	char	*sTexture;
	char	*wTexture;
	char	*eTexture;
	char	*fTexture;
	char	*cTexture;
	int		*colors;
	double	angle_d;
	double	angle_r;
}	t_data;

// FUNCTIONS

/* Parsing & Check */

void	parse_all(t_data *data, int argc, char *file_path);
void	error_msg(char *message);
void	check_extension(char *path);
void	check_map(t_data *data);
char	*next_line(char *line, int fd);
int		is_only_spaces(char *line);
int		check_texture(char *line, int rgb);
int		check_rgb(char **splitted);

/* Events */

int		exit_cub(t_data *data);
int		handle_key(int key, t_data *data);

/* Moves */
void    move_w(t_data *data);
void    move_s(t_data *data);
void    move_d(t_data *data);
void    move_a(t_data *data);

/* Math */

void    calculations(t_data *data);

/* Picture */

void	drawing(int x, t_data *data, double *dist, double *ray);

#endif