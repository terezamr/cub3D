/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <rade-sar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:02:51 by mvicente          #+#    #+#             */
/*   Updated: 2023/08/24 11:04:06 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	move_w(t_data *data)
{
	if (data->map[(int)(data->pos_x + data->dir_x)][(int)data->pos_y] == '0')
		data->pos_x += data->dir_x;
	if (data->map[(int)data->pos_x][(int)(data->pos_y + data->dir_y)] == '0')
		data->pos_y += data->dir_y;
}

void	move_s(t_data *data)
{
	if (data->map[(int)(data->pos_x - data->dir_x)][(int)data->pos_y] == '0')
		data->pos_x -= data->dir_x;
	if (data->map[(int)data->pos_x][(int)(data->pos_y - data->dir_y)] == '0')
		data->pos_y -= data->dir_y;
}

void	move_a(t_data *data)
{
	double	dir1;
	double	dir2;

	dir1 = data->dir_x;
	dir2 = -data->dir_y;
	if (data->map[(int)(data->pos_x + dir2)][(int)(data->pos_y)] == '0')
		data->pos_x += dir2;
	if (data->map[(int)(data->pos_x)][(int)(data->pos_y + dir1)] == '0')
		data->pos_y += dir1;
}

void	move_d(t_data *data)
{
	double	dir1;
	double	dir2;

	dir1 = -data->dir_x;
	dir2 = data->dir_y;
	if (data->map[(int)(data->pos_x + dir2)][(int)(data->pos_y)] == '0')
		data->pos_x += dir2;
	if (data->map[(int)(data->pos_x)][(int)(data->pos_y + dir1)] == '0')
		data->pos_y += dir1;
}
