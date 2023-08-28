/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   picture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <rade-sar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:25:56 by mvicente          #+#    #+#             */
/*   Updated: 2023/08/24 11:03:29 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	get_picture_vars(t_data *data, int side, double *dist)
{
	if (side == 0)
		data->distance = (dist[2] - dist[0]);
	else
		data->distance = (dist[3] - dist[1]);
	data->height = WINDOW_HEIGHT / data->distance;
	data->start = WINDOW_HEIGHT / 2 - data->height / 2;
	data->end = WINDOW_HEIGHT / 2 + data->height / 2;
}

unsigned int	get_pixel_texture(t_data *data, int y, double *ray)
{
	char	*color;
	float	coord_x;
	float	coord_y;
	int		i;

	i = get_i(data, ray);
	if (data->side == 0)
		coord_x = data->pos_y + data->distance * ray[1];
	else
		coord_x = data->pos_x + data->distance * ray[0];
	coord_x = coord_x - floor(coord_x);
	coord_x = coord_x * data->wall[i].width;
	coord_y = ((y - data->start) * data->wall[i].height)
		/ ((data->end - data->start));
	color = (data->wall[i].addr + ((int)coord_y
				* data->wall[i].line_len
				+ (int)coord_x * (data->wall[i].bpp / 8)));
	return (*(unsigned int *)color);
}

void	drawing(int x, t_data *data, double *dist, double *ray)
{
	int				y;
	unsigned int	color;

	y = 0;
	get_picture_vars(data, data->side, dist);
	while (y < WINDOW_HEIGHT)
	{
		if (y >= 0 && y <= data->start)
			ft_mlx_pixel_put(data, x, y, data->colors[1]);
		else if (y > data->start && y < data->end)
		{
			color = get_pixel_texture(data, y, ray);
			ft_mlx_pixel_put(data, x, y, color);
		}
		else if (y >= data->end)
			ft_mlx_pixel_put(data, x, y, data->colors[0]);
		y++;
	}
}
