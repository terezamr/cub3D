/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:10:12 by mvicente          #+#    #+#             */
/*   Updated: 2023/07/06 16:19:19 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	vars_init(t_data *data)
{
	data->mlx = 0;
	data->win = 0;
	data->img.offset_r = -2;
	data->img.offset_i = 2;
	data->posX = 8;
	data->posY = 1;
	data->angle_d = 90;
	data->angle_r = (data->angle_d * PI) / 180;
	data->dirX = cos(data->angle_r);
	data->dirY = sin(data->angle_r);
	data->planeX = 0.66;
	data->planeY = 0;
	data->distance = 0;
	data->height = 0;
	data->start = 0;
	data->end = 0;
	data->hit = 0;
	data->step_x = 0;
	data->step_y = 0;
	data->side = 0;
	data->nTexture = 0;
	data->sTexture = 0;
	data->wTexture = 0;
	data->eTexture = 0;
	data->fTexture = 0;
	data->cTexture = 0;
}

int	render(t_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	calculations(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.mlx_img, 0, 0);
	return (1);
}

int	**get_map(void)
{
	int	i;
	int	j;
	int	**map;

	i = 0;
	map = malloc(sizeof(int *) * 20);
	while (i < 20)
	{
		map[i] = malloc(sizeof(int) * 21);
		i++;
	}
	i = 0;
	while (i < 20)
	{
		j = 0;
		if (i == 0 || i == 19)
		{
			while (j < 20)
			{
				map[i][j] = 1;
				j++;
			}
		}
		else
		{
			map[i][j] = 1;
			j++;
			while (j < 20)
			{
				map[i][j] = 0;
				j++;
			}
			map[i][j] = 1;
		}
		i++;
	}
	map[5][10] = 1;
	map[15][10] = 1;
	map[9][5] = 1;
	return (map);
}

int	main(int argc, char **argv)
{
	t_data	data;

	vars_init(&data);
	parse_all(&data, argc, argv[1]);
	data.world_map = get_map();
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Cub3d");
	data.img.mlx_img = mlx_new_image(data.mlx, WINDOW_WIDTH,
			WINDOW_HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp,
			&data.img.line_len, &data.img.endian);
	mlx_loop_hook(data.mlx, render, &data);
	mlx_key_hook(data.win, handle_key, &data);
	mlx_hook(data.win, 17, 1L << 17, exit_cub, &data);
	mlx_loop(data.mlx);
}
