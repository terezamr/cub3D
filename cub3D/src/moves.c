/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <rade-sar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:02:51 by mvicente          #+#    #+#             */
/*   Updated: 2023/08/24 14:07:27 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

// data->pos_x > x => north
// data->pos_x < x => south
// data->pos_y < y => east
// data->pos_y > y => west

// printf("XY : x: %f, y: %f\n", x, y);
// printf("(int)XY : x: %d, y: %d\n", (int)ceil(x), (int)ceil(y));
// printf("char: %c\n", data->map[(int)x][(int)y]);

int	check_xy(t_data *data, double x, double y)
{
	if ((data->pos_x > x && data->pos_y > y
		&& data->map[(int)(x - 0.1)][(int)(y - 0.1)] != '1')
		|| (data->pos_x < x && data->pos_y < y
		&& data->map[(int)(x + 0.1)][(int)(y + 0.1)] != '1')
		|| (data->pos_x > x && data->map[(int)(x - 0.1)][(int)y] != '1')
		|| (data->pos_x < x && data->map[(int)(x + 0.1)][(int)y] != '1')
		|| (data->pos_y > y && data->map[(int)(x)][(int)(y - 0.1)] != '1')
		|| (data->pos_y < y && data->map[(int)(x)][(int)(y + 0.1)] != '1'))
		return (1);
	return (0);
}

void	move_w(t_data *data)
{
	double	x;
	double	y;

	x = data->pos_x + STEP * data->dir_x;
	y = data->pos_y + STEP * data->dir_y;
	if (data->map[(int)x][(int)y] != '1' && check_xy(data, x, y))
	{
		data->pos_x = x;
		data->pos_y = y;
	}
}

void	move_s(t_data *data)
{
	double	x;
	double	y;

	x = data->pos_x - STEP * data->dir_x;
	y = data->pos_y - STEP * data->dir_y;
	if (data->map[(int)x][(int)y] != '1' && check_xy(data, x, y))
	{
		data->pos_x = x;
		data->pos_y = y;
	}
}

void	move_a(t_data *data)
{
	double	x;
	double	y;
	x = data->pos_x - STEP * data->dir_y;
	y = data->pos_y + STEP * data->dir_x;
	if (data->map[(int)x][(int)y] != '1' && check_xy(data, x, y))
	{
		data->pos_x = x;
		data->pos_y = y;
	}
}

void	move_d(t_data *data)
{
	double	x;
	double	y;

	x = data->pos_x + STEP * data->dir_y;
	y = data->pos_y - STEP * data->dir_x;
	if (data->map[(int)x][(int)y] != '1' && check_xy(data, x, y))
	{
		data->pos_x = x;
		data->pos_y = y;
	}
}