/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   picture_aux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <rade-sar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:25:56 by mvicente          #+#    #+#             */
/*   Updated: 2023/08/24 10:55:27 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	get_rgb(int r, int g, int b)
{
	return (0 << 24 | (int)r << 16 | (int)g << 8 | (int)b);
}

void	ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*index;

	index = data->img.addr + (y * data->img.line_len + x * (data->img.bpp / 8));
	*(unsigned int *)index = color;
}

int	get_i(t_data *data, double *ray)
{
	int		i;

	if (data->side == 1)
	{
		if (ray[1] < 0)
			i = 2;
		else
			i = 3;
	}
	else
	{
		if (ray[0] < 0)
			i = 0;
		else
			i = 1;
	}
	return (i);
}
