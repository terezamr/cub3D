/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   picture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:25:56 by mvicente          #+#    #+#             */
/*   Updated: 2023/06/29 15:48:56 by mvicente         ###   ########.fr       */
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
	data->start = (-data->height / 2) + (WINDOW_HEIGHT / 2);
	if (data->start < 0)
		data->start = 0;
	data->end = (data->height / 2) + (WINDOW_HEIGHT / 2);
	if (data->end >= WINDOW_HEIGHT)
		data->end = WINDOW_HEIGHT - 1;
}

void	drawing(int x, t_data *data, double *dist)
{
	char	*index;
    int     y;

    y = 0;
    get_picture_vars(data, data->side, dist);
    while (y < WINDOW_HEIGHT)
    {
        index = data->img.addr + (y * data->img.line_len
                    + x * (data->img.bpp / 8));
        // if (y < data->start)
        //     *(int *)index = BLACK_PIXEL;
        if (y > data->end)
            *(int *)index = WHITE_PIXEL;
        else if (y>= data->start && y <= data->end)
        {
            // {
            //     index = data->img.addr + (y * data->img.line_len
            //             + x * (data->img.bpp / 8));
            //     *(int *)index = PINK_PIXEL;
            // }
            // else
            *(int *)index = PINK_PIXEL;
        }
        y++;
    }
}
