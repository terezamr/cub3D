/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:10:12 by mvicente          #+#    #+#             */
/*   Updated: 2023/06/29 15:56:46 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	vars_init(t_data *data)
{
	data->mlx = 0;
	data->win = 0;
	data->img.offset_r = -2;
	data->img.offset_i = 2;
	data->posX = 2;
	data->posY = 1;
	data->dirX = 0;
	data->dirY = 1;
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
	map = malloc(sizeof(int *) * 10);
	while (i < 10)
	{
		map[i] = malloc(sizeof(int) * 10);
		i++;
	}
	i = 0;
	while (i < 10)
	{
		j = 0;
		if (i == 0 || i == 9)
		{
			while (j < 10)
			{
				map[i][j] = 1;
				j++;
			}
		}
		else
		{
			map[i][j] = 1;
			j++;
			while (j < 9)
			{
				map[i][j] = 0;
				j++;
			}
			map[i][j] = 1;
		}
		i++;
	}
	i = 0;
	while (i < 10)
	{
		j = 0;	
		while (j < 10)
		{
			printf("%i ", map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	return (map);
}

int	main(int argc, char **argv)
{
	t_data	data;

	(void)argv;
	if (argc != 1)
		return (0);
	vars_init(&data);
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
