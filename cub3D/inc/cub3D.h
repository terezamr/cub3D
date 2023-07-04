/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:57:26 by mvicente          #+#    #+#             */
/*   Updated: 2023/06/29 15:42:06 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// INCLUDES

# include "./libft/libft.h"
# include "./minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>

// DEFINES

# define WINDOW_WIDTH 1400
# define WINDOW_HEIGHT 1400
# define ESCAPE 65307

# define WHITE_PIXEL 0xc0c0c0
# define BLACK_PIXEL 0xFFFFFF
# define PINK_PIXEL 0xFFC0CB

# define INF 1000000

// ERROR HANDLING

# define OPEN_ERROR "File not found."
# define DIR_ERROR "File path is a directory"
# define INVALID_ARGS "The program should take 1 argument."
# define INVALID_TYPE "Texture type must be composed by one or two characters."
# define INVALID_TEXTURE "Texture file not found."
# define INVALID_ARGS "The program should take 1 argument."
# define INVALID_MAP "Invalid map."
# define INVALID_CHAR "Invalid character found."

// STRUCTS

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
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
	int		**world_map;
	int		distance;
	int		height;
	int		start;
	int		end;
	int		hit;
	int		step_x;
	int		step_y;
	int		side;
	char	*nTexture;
	char	*sTexture;
	char	*wTexture;
	char	*eTexture;
	char	*fTexture;
	char	*cTexture;
}	t_data;

// FUNCTIONS

/* Parsing */

void	parse_all(t_data *data, int argc, char *file_path);
void	error_msg(char *message);

/* Events */

int		exit_cub(t_data *data);
int		handle_key(int key, t_data *data);

/* Math */

void    calculations(t_data *data);

/* Picture */

void	drawing(int x, t_data *data, double *dist);




#endif