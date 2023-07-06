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

// DEFINES

# define WINDOW_WIDTH 500
# define WINDOW_HEIGHT 500
# define ESCAPE 65307
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100

# define WHITE_PIXEL 0xFFFFFF
# define BLACK_PIXEL 0x000000
# define PINK_PIXEL 0xFFC0CB
# define PINK1_PIXEL 0xe5acb6
# define PINK2_PIXEL 0xcc99a2

# define INF 1000000
#define PI 3.141592654

// ERROR HANDLING

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
	double	distance;
	double	height;
	int		start;
	int		end;
	int		hit;
	int		step_x;
	int		step_y;
	int		side;
	double	angle_d;
	double	angle_r;
}	t_data;

// FUNCTIONS

/* Geral */
int	error_msg(char *message);

/* Events */
int	exit_cub(t_data *data);
int	handle_key(int key, t_data *data);

/* Math */
void    calculations(t_data *data);

/*Picture*/
void	drawing(int x, t_data *data, double *dist);

#endif