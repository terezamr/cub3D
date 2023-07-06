#include "../inc/cub3D.h"

int	get_map_height(char *line, int fd)
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
			error_msg(INVALID_MAP);
		line = next_line(line, fd);
	}
	free(line);
	close(fd);
	return (height);
}

void	parse_map(t_data *data, int lineOfMap)
{
	int		j;
	int		i;
	int		fd;
	char	*line;

	i = 0;
	j = 0;
	fd = open(data->file_path, O_RDONLY);
	data->world_map = malloc(sizeof(char *) * (data->map_height + 1));
	if (!data->world_map)
		error_msg(MLC_ERROR);
	line = get_next_line(fd);
	while (j++ != lineOfMap)
		line = next_line(line, fd);
	while (line && !is_only_spaces(line))
	{
		data->world_map[i++] = ft_strdup(line);
		line = next_line(line, fd);
	}
	free(line);
	close(fd);
}

int	read_textures(t_data *data, char *line)
{
	if (!data->nTexture && check_texture(line))
		data->nTexture = ft_strdup(line);
	else if (!data->sTexture && check_texture(line))
		data->sTexture = ft_strdup(line);
	else if (!data->wTexture && check_texture(line))
		data->wTexture = ft_strdup(line);
	else if (!data->eTexture && check_texture(line))
		data->eTexture = ft_strdup(line);
	else if (!data->fTexture && check_rgb(line))
		data->fTexture = ft_strdup(line);
	else if (!data->cTexture && check_rgb(line))
		data->cTexture = ft_strdup(line);
	else
		return (0);
	return (1);
}

void	parse_file(t_data *data, int fd)
{
    char	*line;
	int		lineOfMap;

	lineOfMap = 0;
    line = get_next_line(fd);
    while (line)
	{
		while (line && is_only_spaces(line))
		{
			line = next_line(line, fd);
			lineOfMap++;
		}
		if (!read_textures(data, line)) {
			data->map_height = get_map_height(line, fd);
			break ;
		}
		line = next_line(line, fd);
		lineOfMap++;
	}
	parse_map(data, lineOfMap);
}

void	parse_all(t_data *data, int argc, char *file_path)
{
    int		fd;

	(void)data;
    if (argc != 2)
		error_msg(INVALID_ARGS);
    fd = open(file_path, __O_DIRECTORY);
    if (fd != -1)
        error_msg(DIR_ERROR);
    fd = open(file_path, O_RDONLY);
    if (fd == -1)
	{
        error_msg(OPEN_ERROR);
	}
	check_extension(file_path);
	data->file_path = file_path;
    parse_file(data, fd);
    close(fd);
}