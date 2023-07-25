/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   picture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:25:56 by mvicente          #+#    #+#             */
/*   Updated: 2023/07/06 13:50:02 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void    get_picture_vars(t_data *data, int side, double *dist)
{
    if (side == 0)
		data->distance = (dist[2] - dist[0]);
	else
		data->distance = (dist[3] - dist[1]);
	data->height = WINDOW_HEIGHT / data->distance;
	data->start = WINDOW_HEIGHT / 2 - data->height / 2;
	if (data->start < 0)
		data->start = 0;
	data->end = WINDOW_HEIGHT / 2 + data->height / 2;
	if (data->end >= WINDOW_HEIGHT)
		data->end = WINDOW_HEIGHT - 1;
}

void	ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*index;

	index = data->img.addr + (y * data->img.line_len + x * (data->img.bpp / 8));
	*(unsigned int*)index = color;
}

void	drawing(int x, t_data *data, double *dist, double *ray)
{
    int     y;
	double	wallX;
	int		texX;
	double	step;
	double	texPos;
	int		texY;
	char	*color;

    y = 0;
    get_picture_vars(data, data->side, dist);
	if (data->side == 0)
		wallX = data->posY + data->distance * ray[1];
	else
		wallX = data->posX + data->distance * ray[0];
	wallX = wallX - floor(wallX);
	texX = (wallX * data->wall.width);
	if ((data->side == 0 && ray[0] > 0) || (data->side == 1 && ray[0] < 0))
		texX = data->wall.width - texX - 1;
	step = 1.0 * data->wall.height / data->height;
	texPos = (data->start - WINDOW_HEIGHT / 2 + data->height  / 2) * step;
    while (y < WINDOW_HEIGHT)
    {
		if (y >= 0 && y < data->start)
			ft_mlx_pixel_put(data, x, y, data->colors[0]);
		else if (y >= data->end)
			ft_mlx_pixel_put(data, x, y, data->colors[1]);
		else if (y >= data->start && y < data->end)
		{
			texY = (int)texPos;
			texPos += step;
			color = (data->wall.addr + (texY * data->wall.line_len + texX * (data->wall.bpp / 8)));
			ft_mlx_pixel_put(data, x, y, *(unsigned int*)color);
		}
		y++;
    }
}
