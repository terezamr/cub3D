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

# include "minilibx-linux/mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <X11/keysym.h>
# include <X11/X.h>

# define WINDOW_WIDTH 1400
# define WINDOW_HEIGHT 1400

# define WHITE_PIXEL 0xc0c0c0
# define BLACK_PIXEL 0xFFFFFF

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
}	t_data;

/*Events*/
int	exit_cub(t_data *data);
int	handle_key(int key, t_data *data);

/*Math*/
void    calculations(t_data *data);

/*Picture*/
void	drawing(int x, t_data *data, int side, double *dist);

#endif