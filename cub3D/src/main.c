/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <rade-sar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:10:12 by mvicente          #+#    #+#             */
/*   Updated: 2023/08/24 12:50:33 by rade-sar         ###   ########.fr       */
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
	data->dir_x = 0;
	data->dir_y = sig;
	data->plane_x = 0.66 * sig;
	data->plane_y = 0;
}

void	get_dir(t_data *data)
{
	if (data->letter == 'E')
		direction_values(data, 1);
	else if (data->letter == 'W')
		direction_values(data, -1);
	else if (data->letter == 'S')
	{
		data->dir_x = 1;
		data->dir_y = 0;
		data->plane_x = 0;
		data->plane_y = -0.66;
	}
	else if (data->letter == 'N')
	{
		data->dir_x = -1;
		data->dir_y = 0;
		data->plane_x = 0;
		data->plane_y = 0.66;
	}
	data->dir_x_init = data->dir_x;
	data->dir_y_init = data->dir_y;
}

void	init_tex_image(t_data *data)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		data->wall[i].img = mlx_xpm_file_to_image(data->mlx, data->textures[i],
				&data->wall[i].width, &data->wall[i].height);
		if (!data->wall[i].img)
			return ;
		data->wall[i].addr = mlx_get_data_addr(data->wall[i].img,
				&data->wall[i].bpp, &data->wall[i].line_len,
				&data->wall[i].endian);
		free(data->textures[i++]);
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	vars_init(&data);
	parse_all(&data, argc, argv[1]);
	get_dir(&data);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Cub3D");
	data.img.mlx_img = mlx_new_image(data.mlx, WINDOW_WIDTH,
			WINDOW_HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp,
			&data.img.line_len, &data.img.endian);
	init_tex_image(&data);
	mlx_loop_hook(data.mlx, render, &data);
	// mlx_key_hook(data.win, handle_key, &data);
	mlx_hook(data.win, 02, (1L << 0), handle_key, &data);
	mlx_hook(data.win, 17, 1L << 17, exit_cub, &data);
	mlx_loop(data.mlx);
}
