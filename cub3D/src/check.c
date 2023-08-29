/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <rade-sar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 10:38:24 by rade-sar          #+#    #+#             */
/*   Updated: 2023/08/24 10:40:55 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	check_extension(t_data *data, char *path)
{
	char	**splitted_path;

	splitted_path = ft_split(path, '.');
	if (!ft_equals(splitted_path[ft_mtxlen(splitted_path) - 1], "cub"))
	{
		ft_free_mtx(splitted_path);
		error_msg(data, INVALID_EXTENSION);
	}
	ft_free_mtx(splitted_path);
}

void	check_numbs(t_data *data, char **rgb, int i, char *line)
{
	char	*trim;

	trim = rgb[i];
	if (ft_atol(trim) < 0 || ft_atol(trim) > 255
		|| (ft_atol(trim) == 0 && !ft_equals(trim, "0")))
	{
		free(trim);
		free(line);
		ft_free_mtx(rgb);
		error_msg(data, INVALID_RGB);
	}
	free(trim);
}

void	check_rgb(t_data *data, char **splitted, int pos, char *line)
{
	char	**rgb;
	int		i;

	rgb = ft_split(splitted[1], ',');
	ft_free_mtx(splitted);			
	if (!rgb || !rgb[0] || !rgb[1] || !rgb[2])
	{
		free(line);
		error_msg(data, INVALID_RGB);
	}
	i = -1;
	while (++i != 3)
		check_numbs(data, rgb, i, line);
	data->colors[pos - 1] = get_rgb(ft_atol(rgb[0]), ft_atol(rgb[1]),
			ft_atol(rgb[2]));
	ft_free_mtx(rgb);
}

void	check_texture(t_data *data, char **splitted, int pos, char *line)
{
	int		fd;
	int		fd2;
	char	*path;

	path = splitted[1];
	ft_free_mtx(splitted);
	fd = open(path, __O_DIRECTORY);
	fd2 = open(path, O_RDONLY);
	if (fd != -1 || fd2 == -1)
	{
		if (fd != -1)
			close(fd);
		free(line);
		free(path);
		error_msg(data, INVALID_TEXTURE);
	}
	close(fd2);
	data->textures[pos] = ft_strdup(path);
	free(path);
}

void	check_texture_rgb(t_data *data, char *line, int pos, int rgb)
{
	char	**splitted;
	char	*trim;

	trim = ft_strtrim(line, "\n");
	splitted = ft_split(trim, ' ');
	free(trim);
	if (!splitted || !splitted[0]
		|| ft_strlen(splitted[0]) < 1 || ft_strlen(splitted[0]) > 2
		|| !splitted[1] || ft_mtxlen(splitted) >= 3)
	{
		ft_free_mtx(splitted);
		free(line);
		error_msg(data, INVALID_TEXTURE);
	}
	if (rgb)
		return (check_rgb(data, splitted, rgb, line));
	check_texture(data, splitted, pos, line);
}
