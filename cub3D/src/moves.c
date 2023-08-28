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

void	move_w(t_data *data)
{
	double	x;
	double	y;

	x = data->pos_x + STEP * data->dir_x;
	y = data->pos_y + STEP * data->dir_y;
	printf("dist %f\n", data->distance);
	if (data->map[(int)x][(int)y] != '1' && data->distance > 0.2)
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
	if (data->map[(int)x][(int)y] != '1' && data->map[(int)(x + 0.1)][(int)y] != '1')
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
	if (data->map[(int)x][(int)y] != '1' && data->map[(int)(x + 0.1)][(int)(y)] != '1')
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
	if (data->map[(int)x][(int)y] != '1' && data->map[(int)(x + 0.1)][(int)(y)] != '1')
	{
		data->pos_x = x;
		data->pos_y = y;
	}
}
