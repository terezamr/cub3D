/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 10:38:24 by rade-sar          #+#    #+#             */
/*   Updated: 2023/08/29 18:58:20 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	check_re(t_data *data, int pos, int rgb)
{
	if (!rgb && data->textures[pos])
	{
		data->error = INVALID_ELEMENT;
		return (0);
	}
	else if (rgb && data->colors[pos] != -1)
	{
		data->error = INVALID_ELEMENT;
		return (0);
	}
	return (1);
}

void	save_textures(t_data *data, char *id, char *texture_path, int rgb)
{
	if (ft_equals(id, "NO") && check_re(data, 0, 0))
		data->textures[0] = ft_strdup(texture_path);
	else if (ft_equals(id, "SO") && check_re(data, 1, 0))
		data->textures[1] = ft_strdup(texture_path);
	else if (ft_equals(id, "WE") && check_re(data, 2, 0))
		data->textures[2] = ft_strdup(texture_path);
	else if (ft_equals(id, "EA") && check_re(data, 3, 0))
		data->textures[3] = ft_strdup(texture_path);
	else if (ft_equals(id, "F") && check_re(data, 0, 1))
		data->colors[0] = rgb;
	else if (ft_equals(id, "C") && check_re(data, 1, 1))
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
			error_msg(data, INVALID_ELEMENT);
		}
	}
}

void	check_rgb(t_data *data, char **splitted, char *line)
{
	char	**rgb;

	rgb = ft_split(splitted[1], ',');
	if (!rgb || ft_mtxlen(rgb) < 3)
	{
		free(line);
		ft_free_mtx(rgb);
		ft_free_mtx(splitted);
		error_msg(data, INVALID_ELEMENT);
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
		error_msg(data, INVALID_ELEMENT);
	}
	close(fd2);
	save_textures(data, splitted[0], path, 0);
	free(path);
}
