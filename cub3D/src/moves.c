/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:02:51 by mvicente          #+#    #+#             */
/*   Updated: 2023/07/06 16:28:56 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void    move_w(t_data *data)
{
    if (data->map[(int)(data->posX + data->dirX)][(int)data->posY] == '0')
		data->posX += data->dirX;
	if (data->map[(int)data->posX][(int)(data->posY + data->dirY)] == '0')
		data->posY += data->dirY;
}

void    move_s(t_data *data)
{
    if (data->map[(int)(data->posX - data->dirX)][(int)data->posY] == '0')
		data->posX -= data->dirX;
	if (data->map[(int)data->posX][(int)(data->posY - data->dirY)] == '0')
		data->posY -= data->dirY;
}

void    move_a(t_data *data)
{
	double dir1;
	double dir2;

	dir1 = data->dirX;
	dir2 = -data->dirY;
    if (data->map[(int)(data->posX + dir2)][(int)(data->posY)] == '0')
		data->posX += dir2;
	if (data->map[(int)(data->posX)][(int)(data->posY + dir1)] == '0')
		data->posY += dir1;
}

void    move_d(t_data *data)
{
	double dir1;
	double dir2;

	dir1 = -data->dirX;
	dir2 = data->dirY;
    if (data->map[(int)(data->posX + dir2)][(int)(data->posY)] == '0')
		data->posX += dir2;
	if (data->map[(int)(data->posX)][(int)(data->posY + dir1)] == '0')
		data->posY += dir1;
}
