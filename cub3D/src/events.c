/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <rade-sar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:24:40 by mvicente          #+#    #+#             */
/*   Updated: 2023/08/24 13:10:24 by rade-sar         ###   ########.fr       */
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
	free(data->textures);
	exit(0);
}

void	rotate_left(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->dir_x;
	old_plane_x = data->plane_x;
	data->dir_x = data->dir_x * cos(PI / 80) - data->dir_y * sin(PI / 80);
	data->dir_y = old_dir_x * sin(PI / 80) + data->dir_y * cos(PI / 80);
	data->plane_x = data->plane_x * cos(PI / 80) - data->plane_y * sin(PI / 80);
	data->plane_y = old_plane_x * sin(PI / 80) + data->plane_y * cos(PI / 80);
}

void	rotate_right(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->dir_x;
	old_plane_x = data->plane_x;
	data->dir_x = data->dir_x * cos(-PI / 80) - data->dir_y * sin(-PI / 80);
	data->dir_y = old_dir_x * sin(-PI / 80) + data->dir_y * cos(-PI / 80);
	data->plane_x = data->plane_x 
		* cos(-PI / 80) - data->plane_y * sin(-PI / 80);
	data->plane_y = old_plane_x * sin(-PI / 80) + data->plane_y * cos(-PI / 80);
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
