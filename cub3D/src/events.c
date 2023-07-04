/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:24:40 by mvicente          #+#    #+#             */
/*   Updated: 2023/06/29 12:26:00 by mvicente         ###   ########.fr       */
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
	// ft_free_mtx(data->world_map);
}

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
	// free_data(data);
	free(data->mlx);
	exit(0);
}

int	handle_key(int key, t_data *data)
{
	if (key == ESCAPE)
		exit_cub(data);
	return (0);
}

