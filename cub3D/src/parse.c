#include "../inc/cub3D.h"

char	*next_line(char *line, int fd)
{
	free(line);
	return (get_next_line(fd));
}

void	parse_map(t_data *data, char *line, int fd)
{
	int	i;

	i = 0;
	while (line)
	{
		while (ft_equals(line, "\n"))
			line = next_line(line, fd);
		// data->world_map[i++] = line;
		line = next_line(line, fd);
	}
	data->world_map[i] = NULL;
}


void	parse_file(t_data *data, int fd)
{
    char	*line;

    line = get_next_line(fd);
    while (line)
	{
		while (ft_equals(line, "\n"))
			line = next_line(line, fd);
		if (!data->nTexture)
			ft_strcpy(data->nTexture, line);
		else if (!data->sTexture)
			ft_strcpy(data->sTexture, line);
		else if (!data->wTexture)
			ft_strcpy(data->wTexture, line);
		else if (!data->eTexture)
			ft_strcpy(data->eTexture, line);
		else if (!data->fTexture)
			ft_strcpy(data->fTexture, line);
		else if (!data->cTexture)
			ft_strcpy(data->cTexture, line);
		else {
			// parse_map(data, line, fd);
			break ;
		}
		line = next_line(line, fd);
	}
}

void	parse_all(t_data *data, int argc, char *file_path)
{
    int	fd;

	(void)data;
    if (argc != 2)
		error_msg(INVALID_ARGS);
    fd = open(file_path, __O_DIRECTORY);
    if (fd != -1)
    {
        close(fd);
        error_msg(DIR_ERROR);
    }
    fd = open(file_path, O_RDONLY);
    if (fd == -1)
        error_msg(OPEN_ERROR);
    // parse_file(data, fd);
    close(fd);
}