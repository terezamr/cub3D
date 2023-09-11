/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 10:38:41 by rade-sar          #+#    #+#             */
/*   Updated: 2023/08/29 13:53:10 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	get_map_height(t_data *data, char *line, int fd)
{
	int		height;

	height = 0;
	while (line && !is_only_spaces(line)) 
	{
		line = next_line(line, fd);
		height++;
	}
	while (line)
	{
		if (!is_only_spaces(line))
		{
			free(line);
			error_msg(data, INVALID_MAP);
		}
		line = next_line(line, fd);
	}
	close(fd);
	return (height);
}

void	parse_map(t_data *data, int map_line)
{
	int		j;
	int		i;
	int		fd;
	char	*line;

	i = 0;
	j = 0;
	fd = open(data->file_path, O_RDONLY);
	data->map = malloc(sizeof(char *) * (data->map_height + 1));
	if (!data->map)
		error_msg(data, MLC_ERROR);
	line = get_next_line(fd);
	while (j++ != map_line)
		line = next_line(line, fd);
	while (line && !is_only_spaces(line))
	{
		data->map[i++] = ft_strdup(line);
		line = next_line(line, fd);
	}
	data->map[i] = 0;
	free(line);
	close(fd);
}

int	read_textures(t_data *data, char *line)
{
	if (!data->textures[0])
		check_texture_rgb(data, line);
	else if (!data->textures[1])
		check_texture_rgb(data, line);
	else if (!data->textures[2])
		check_texture_rgb(data, line);
	else if (!data->textures[3])
		check_texture_rgb(data, line);
	else if (data->colors[0] == -1)
		check_texture_rgb(data, line);
	else if (data->colors[1] == -1)
		check_texture_rgb(data, line);
	else
		return (0);
	return (1);
}

void	parse_file(t_data *data, int fd)
{
	char	*line;
	int		h;
	int		map_line;

	map_line = 0;
	line = get_next_line(fd);
	while (line)
	{
		while (line && is_only_spaces(line))
		{
			line = next_line(line, fd);
			map_line++;
		}
		if (!read_textures(data, line))
		{
			h = get_map_height(data, line, fd);
			data->map_height = h;
			break ;
		}
		line = next_line(line, fd);
		map_line++;
	}
	parse_map(data, map_line);
}

void	parse_all(t_data *data, int argc, char *file_path)
{
	int		fd;

	if (argc != 2)
		error_msg(data, INVALID_ARGS);
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		error_msg(data, OPEN_ERROR);
	check_extension(data, file_path);
	data->file_path = file_path;
	parse_file(data, fd);
	check_map(data);
	close(fd);
}
