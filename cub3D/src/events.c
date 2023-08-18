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
	int	i;

	i = 0;
	if (!data)
		exit(0);
	if (data->img.mlx_img)
		mlx_destroy_image(data->mlx, data->img.mlx_img);
	if (data->win && data->mlx)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	while (i != data->map_height)
		free(data->map[i++]);
	free(data->map);
	free(data->mlx);
	free(data->colors);
	free(data->map_c);
	exit(0);
}

void	rotate_left(t_data *data)
{
	double oldDirX;
	double oldPlaneX;
	
	oldDirX = data->dirX;
	oldPlaneX = data->planeX;
	data->dirX = data->dirX * cos(PI / 15) - data->dirY * sin(PI / 15);
    data->dirY = oldDirX * sin(PI / 15) + data->dirY * cos(PI / 15);
	data->planeX = data->planeX * cos(PI / 15) - data->planeY * sin(PI / 15);
	data->planeY = oldPlaneX * sin(PI / 15) + data->planeY * cos(PI / 15);
}

void	rotate_right(t_data *data)
{
	double oldDirX;
	double oldPlaneX;
	
	oldDirX = data->dirX;
	oldPlaneX = data->planeX;
	data->dirX = data->dirX * cos(-PI / 15) - data->dirY * sin(-PI / 15);
    data->dirY = oldDirX * sin(-PI / 15) + data->dirY * cos(-PI / 15);
	data->planeX = data->planeX * cos(-PI / 15) - data->planeY * sin(-PI / 15);
	data->planeY = oldPlaneX * sin(-PI / 15) + data->planeY * cos(-PI / 15);
}

int	handle_key(int key, t_data *data)
{
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
		rotate_left(data);
	else if (key == KEY_RIGHT)
		rotate_right(data);
	return (0);
}
