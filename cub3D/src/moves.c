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
    if (data->world_map[(int)(data->posX + data->dirX)][(int)data->posY] == 0)
		data->posX += data->dirX;
	if (data->world_map[(int)data->posX][(int)(data->posY + data->dirY)] == 0)
		data->posY += data->dirY;
}

void    move_s(t_data *data)
{
    if (data->world_map[(int)(data->posX - data->dirX)][(int)data->posY] == 0)
		data->posX -= data->dirX;
	if (data->world_map[(int)data->posX][(int)(data->posY - data->dirY)] == 0)
		data->posY -= data->dirY;
}

void    move_d(t_data *data)
{
    if (data->world_map[(int)(data->posX + data->dirY)][(int)data->posY] == 0)
		data->posX += data->dirY;
	if (data->world_map[(int)data->posX][(int)(data->posY + data->dirX)] == 0)
		data->posY += data->dirX;
}

void    move_a(t_data *data)
{
    if (data->world_map[(int)(data->posX - data->dirY)][(int)data->posY] == 0)
		data->posX += data->dirY;
	if (data->world_map[(int)data->posX][(int)(data->posY - data->dirX)] == 0)
		data->posY += data->dirX;
}
    
