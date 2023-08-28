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

double check_xy(t_data *data, double x, double y, char c)
{
	if (c == 'x')
	{
		if ((int)x <= 1)
			x = 1.5;
		if ((int)x + 1 >= data->map_height - 1)
			x = data->map_height - 1.5;
		return (x);
	}
	if ((int)y <= 1)
		y = 1.5;
	if (round(y) >= (int)ft_strlen(data->map[(int)x]) - 2)
		y = ft_strlen(data->map[(int)x]) - 2.5;
	return (y);
}

void	move_w(t_data *data)
{
	double	x;
	double	y;

	x = data->pos_x + data->dir_x;
	y = data->pos_y + data->dir_y;
	x = check_xy(data, x, y, 'x');
	y = check_xy(data, x, y, 'y');
	if (data->map[(int)x][(int)y] != '1')
	{
		data->pos_x = x;
		data->pos_y = y;
	}
	
}

void	move_s(t_data *data)
{
	double	x;
	double	y;

	x = data->pos_x - data->dir_x;
	y = data->pos_y - data->dir_y;
	x = check_xy(data, x, y, 'x');
	y = check_xy(data, x, y, 'y');
	if (data->map[(int)x][(int)y] != '1')
	{
		data->pos_x = x;
		data->pos_y = y;
	}
	
}

void	move_a(t_data *data)
{
	double	x;
	double	y;

	x = data->pos_x - data->dir_y;
	y = data->pos_y + data->dir_x;
	x = check_xy(data, x, y, 'x');
	y = check_xy(data, x, y, 'y');
	if (data->map[(int)x][(int)y] != '1')
	{
		data->pos_x = x;
		data->pos_y = y;
	}
}

void	move_d(t_data *data)
{
	double	x;
	double	y;

	x = data->pos_x + data->dir_y;
	y = data->pos_y - data->dir_x;
	x = check_xy(data, x, y, 'x');
	y = check_xy(data, x, y, 'y');
	if (data->map[(int)x][(int)y] != '1')
	{
		data->pos_x = x;
		data->pos_y = y;
	}
}
