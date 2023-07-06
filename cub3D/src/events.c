/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:24:40 by mvicente          #+#    #+#             */
/*   Updated: 2023/07/06 16:20:08 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	exit_cub(t_data *data)
{
	if (!data)
		exit(0);
	if (data->img.mlx_img)
		mlx_destroy_image(data->mlx, data->img.mlx_img);
	if (data->win && data->mlx)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}

int	handle_key(int key, t_data *data)
{
	if (key == ESCAPE)
		exit_cub(data);
	else if (key == KEY_W)
	{
		if (data->world_map[(int)data->posX][(int)data->posY + 1] == 0)
			data->posY += 1;
	}
	else if (key == KEY_S)
	{
		if (data->world_map[(int)data->posX][(int)data->posY - 1] == 0)
			data->posY -= 1;
	}
	else if (key == KEY_D)
	{
		if (data->world_map[(int)data->posX + 1][(int)data->posY] == 0)
			data->posX += 1;
	}
	else if (key == KEY_A)
	{
		if (data->world_map[(int)data->posX - 1][(int)data->posY] == 0)
			data->posX -= 1;
	}
	else if (key == KEY_RIGHT)
		data->angle_d = data->angle_d - 5;
	else if (key == KEY_LEFT)
		data->angle_d = data->angle_d + 5;
	return (0);
}

