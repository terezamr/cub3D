/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:02:51 by mvicente          #+#    #+#             */
/*   Updated: 2023/08/29 19:37:11 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

// data->pos_x > x => north
// data->pos_x < x => south
// data->pos_y < y => east
// data->pos_y > y => west

int	check_xy(t_data *data, double x, double y)
{
	if (data->map[(int)x][(int)y] == '\0'
		|| ft_isspace(data->map[(int)x][(int)y]))
		return (0);
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
