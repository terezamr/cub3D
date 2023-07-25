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

int		get_rgb(int r, int g, int b)
{
	return (0 << 24 | (int)r << 16 | (int)g << 8 | (int)b);
}

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

// void	ft_mlx_pixel_put2(t_data *data, int x, int y, double *ray)
// {
// 	char			*index;
// 	unsigned int	color;

// 	(void)ray;
// 	if (data->side == 1)
// 		color = get_pixel_texture(data, x, y, ray);
// 	else
// 		color = PINK1_PIXEL;
// 	index = data->img.addr + (y * data->img.line_len + x * (data->img.bpp / 8));
// 	*(unsigned int*)index = color;
// }

void	ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*index;

	index = data->img.addr + (y * data->img.line_len + x * (data->img.bpp / 8));
	*(unsigned int*)index = color;
}

unsigned int	get_pixel_texture(t_data *data, int x, int y, double *ray)
{
	char	*color;
	int		coord_x;
	int		coord_y;
	int		aux;
	t_wall *img;

	img = &data->wall;
	aux = (data->posX + data->planeX * ray[0]);
	coord_y = (y * img->height) / (data->end - data->start);
	coord_x = (x * img->width) / (aux - ceil(aux));
	//printf("coord_x %i coord_y %i\n", coord_x, coord_y);
	color = (img->addr + (coord_y * img->line_len + coord_x * (img->bpp / 8)));
	return (*(unsigned int*)color);
}

void	drawing(int x, t_data *data, double *dist, double *ray)
{
    int   			y;
	unsigned int	color;

    y = 0;
    get_picture_vars(data, data->side, dist);
    while (y < WINDOW_HEIGHT)
    {
		if (y >= 0 && y < data->start)
			ft_mlx_pixel_put(data, x, y, data->colors[0]);
		else if (y >= data->end)
			ft_mlx_pixel_put(data, x, y, data->colors[1]);
		else if (y >= data->start && y < data->end)
		{
			color = get_pixel_texture(data, x, y, ray);
			ft_mlx_pixel_put(data, x, y, color);
		}
		y++;
    }
}
