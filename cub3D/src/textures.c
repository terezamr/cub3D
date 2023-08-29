/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 10:38:24 by rade-sar          #+#    #+#             */
/*   Updated: 2023/08/29 17:47:24 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	save_textures(t_data *data, char *id, char *texture_path, int rgb)
{
	if (ft_equals(id, "NO"))
		data->textures[0] = ft_strdup(texture_path);
	else if (ft_equals(id, "SO"))
		data->textures[1] = ft_strdup(texture_path);
	else if (ft_equals(id, "WE"))
		data->textures[2] = ft_strdup(texture_path);
	else if (ft_equals(id, "EA"))
		data->textures[3] = ft_strdup(texture_path);
	else if (ft_equals(id, "F"))
		data->colors[0] = rgb;
	else if (ft_equals(id, "C"))
		data->colors[1] = rgb;
}

void	check_numbs(t_data *data, char **rgb, char **splitted, char *line)
{
	int	i;

	i = -1;
	while (++i != 3)
	{
		if (ft_atol(rgb[i]) < 0 || ft_atol(rgb[i]) > 255
			|| (ft_atol(rgb[i]) == 0 && !ft_equals(rgb[i], "0")))
		{
			free(line);
			ft_free_mtx(rgb);
			ft_free_mtx(splitted);
			error_msg(data, INVALID_RGB);
		}
	}
}

void	check_rgb(t_data *data, char **splitted, char *line)
{
	char	**rgb;

	rgb = ft_split(splitted[1], ',');
	if (!rgb || !rgb[0] || !rgb[1] || !rgb[2])
	{
		free(line);
		ft_free_mtx(splitted);
		error_msg(data, INVALID_RGB);
	}
	check_numbs(data, rgb, splitted, line);
	save_textures(data, splitted[0], NULL, get_rgb(ft_atol(rgb[0]),
			ft_atol(rgb[1]), ft_atol(rgb[2])));
	ft_free_mtx(rgb);
}

void	check_texture(t_data *data, char **splitted, char *line)
{
	int		fd;
	int		fd2;
	char	*path;

	path = ft_strdup(splitted[1]);
	fd = open(path, __O_DIRECTORY);
	fd2 = open(path, O_RDONLY);
	if (fd != -1 || fd2 == -1)
	{
		if (fd != -1)
			close(fd);
		free(line);
		free(path);
		ft_free_mtx(splitted);
		error_msg(data, INVALID_TEXTURE);
	}
	close(fd2);
	save_textures(data, splitted[0], path, 0);
	free(path);
}
