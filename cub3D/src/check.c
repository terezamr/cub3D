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

char	*next_line(char *line, int fd)
{
	free(line);
	return (get_next_line(fd));
}

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

int	check_numbs(char **rgb, int i)
{
	char	*trim;

	trim = ft_strtrim(rgb[i], "\n");
	if (ft_atol(trim) < 0 || ft_atol(trim) > 255
		|| (ft_atol(trim) == 0 && !ft_equals(trim, "0")))
	{
		free(trim);
		return (1);
	}
	free(trim);
	return (0);
}

int	check_rgb(t_data *data, char **splitted, int pos)
{
	char	**rgb;
	int		i;

	rgb = ft_split(splitted[1], ',');
	if (!rgb || !rgb[0] || !rgb[1] || !rgb[2])
		error_msg(data, INVALID_RGB);
	i = -1;
	while (++i != 3)
	{
		if (check_numbs(rgb, i))
		{
			ft_free_mtx(rgb);
			ft_free_mtx(splitted);			
			error_msg(data, INVALID_RGB);
		}
	}
	data->colors[pos - 1] = get_rgb(ft_atol(rgb[0]), ft_atol(rgb[1]),
			ft_atol(rgb[2]));
	ft_free_mtx(rgb);
	ft_free_mtx(splitted);
	return (1);
}

int	check_texture(t_data *data, int pos, int rgb)
{
	char	**splitted;
	char	*texture_path;
	int		error;
	int		fd;

	error = 0;
	splitted = ft_split(data->line, ' ');
	if (!splitted || !splitted[0] 
		|| ft_strlen(splitted[0]) < 1 || ft_strlen(splitted[0]) > 2
		|| !splitted[1] || ft_mtxlen(splitted) > 3)
		error = 1;
	if (rgb)
		return (check_rgb(data, splitted, rgb));
	texture_path = ft_strtrim(splitted[1], "\n");
	fd = open(texture_path, O_RDONLY);
	if (fd == -1)
		error = 1;
	close(fd);
	data->textures[pos] = ft_strdup(texture_path);
	free(texture_path);
	ft_free_mtx(splitted);
	if (error)
	{
		free(data->line);
		error_msg(data, INVALID_TEXTURE);
	}
	return (1);
}
