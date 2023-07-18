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

void	free_data(t_data *data)
{
	if (data->nTexture)
		free(data->nTexture);
	if (data->sTexture)
		free(data->sTexture);
	if (data->wTexture)
		free(data->wTexture);
	if (data->eTexture)
		free(data->eTexture);
	if (data->fTexture)
		free(data->fTexture);
	if (data->cTexture)
		free(data->cTexture);
	// ft_free_mtx(data->world_map);
}

int	exit_cub(t_data *data)
{
	int	i = 0;
	if (!data)
		exit(0);
	if (data->img.mlx_img)
		mlx_destroy_image(data->mlx, data->img.mlx_img);
	if (data->win && data->mlx)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	while (i < 20)
	{
		free(data->world_map[i]);
		i++;
	}
	free(data->world_map);
	free(data->mlx);
	exit(0);
}

int	handle_key(int key, t_data *data)
{
	double oldDirX;
	double oldPlaneX;
	
	oldDirX = data->dirX;
	oldPlaneX = data->planeX;
	if (key == ESCAPE)
		exit_cub(data);
	else if (key == KEY_W)
		move_w(data);
	else if (key == KEY_S)
		move_s(data);
	else if (key == KEY_D)
		move_d(data);
	else if (key == KEY_A)
		move_a(data);
	else if (key == KEY_LEFT)
	{
		data->angle_r = data->angle_r - PI / 15;
      	data->dirX = data->dirX * cos(PI / 15) - data->dirY * sin(PI / 15);
     	data->dirY = oldDirX * sin(PI / 15) + data->dirY * cos(PI / 15);
		data->planeX = data->planeX * cos(PI / 15) - data->planeY * sin(PI / 15);
		data->planeY = oldPlaneX * sin(PI / 15) + data->planeY * cos(PI / 15);
	}
	else if (key == KEY_RIGHT)
	{
		data->angle_r = data->angle_r - PI / 15;
      	data->dirX = data->dirX * cos(-PI / 15) - data->dirY * sin(-PI / 15);
     	data->dirY = oldDirX * sin(-PI / 15) + data->dirY * cos(-PI / 15);
		data->planeX = data->planeX * cos(-PI / 15) - data->planeY * sin(-PI / 15);
		data->planeY = oldPlaneX * sin(-PI / 15) + data->planeY * cos(-PI / 15);
	}
	return (0);
}
