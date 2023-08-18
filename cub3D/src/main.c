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

int	render(t_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	calculations(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.mlx_img, 0, 0);
	return (1);
}

void	direction_values(t_data *data, int sig)
{
	data->dirX = 0;
	data->dirY = sig;
	data->planeX = 0.66 * sig;
	data->planeY = 0;
}

void	get_dir(t_data *data)
{
	if (data->letter == 'E')
		direction_values(data, 1);
	else if (data->letter == 'O')
		direction_values(data, -1);
	else if (data->letter == 'S')
	{
		data->dirX = 1;
		data->dirY = 0;
		data->planeX = 0;
		data->planeY = -0.66;
	}
	else if (data->letter == 'N')
	{
		data->dirX = -1;
		data->dirY = 0;
		data->planeX = 0;
		data->planeY = 0.66;
	}
	data->dirX_init = data->dirX;
	data->dirY_init = data->dirY;
}

void	init_tex_image(t_data *data)
{
	int		i;
	i = 0;
	while (i < 4)
	{
		data->wall[i].img = mlx_xpm_file_to_image(data->mlx, data->textures[i], &data->wall[i].width, &data->wall[i].height);
		if (!data->wall[i].img)
			return ;
		data->wall[i].addr = mlx_get_data_addr(data->wall[i].img, &data->wall[i].bpp, &data->wall[i].line_len, &data->wall[i].endian);
		free(data->textures[i++]);
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	vars_init(&data);
	parse_all(&data, argc, argv[1]);
	get_dir(&data);
	data.map_width = 14;
	data.map_height = 11;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Cub3D");
	data.img.mlx_img = mlx_new_image(data.mlx, WINDOW_WIDTH,
			WINDOW_HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp,
			&data.img.line_len, &data.img.endian);
	init_tex_image(&data);
	mlx_loop_hook(data.mlx, render, &data);
	mlx_key_hook(data.win, handle_key, &data);
	mlx_hook(data.win, 17, 1L << 17, exit_cub, &data);
	mlx_loop(data.mlx);
}
