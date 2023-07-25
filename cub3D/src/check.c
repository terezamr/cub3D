#include "../inc/cub3D.h"

char	*next_line(char *line, int fd)
{
	free(line);
	return (get_next_line(fd));
}

int	is_only_spaces(char *line)
{
	int	i;

	i = 0;
	while(line[i])
		if (ft_isalnum(line[i++]))
			return (0);
	return (1);
}

void	check_extension(char *path)
{
	char	**splitted_path;

	splitted_path = ft_split(path, '.');
	if (!ft_equals(splitted_path[ft_mtxlen(splitted_path) - 1], "cub"))
	{
		ft_free_mtx(splitted_path);
		error_msg(INVALID_EXTENSION);
	}
	ft_free_mtx(splitted_path);
}

int check_rgb(t_data *data, char **splitted, int pos)
{
    char    **rgb;
    char    *trim;
    int     i;

    rgb = ft_split(splitted[1], ',');
    if (!rgb || !rgb[0] || !rgb[1] || !rgb[2])
        error_msg(INVALID_RGB);
    i = -1;
    while (++i != 3)
    {
        trim = ft_strtrim(rgb[i], "\n");
        if (ft_atol(trim) < 0 || ft_atol(trim) > 255
            || (ft_atol(trim) == 0 && !ft_equals(trim,"0")))
            error_msg(INVALID_RGB);
        free(trim);
    }
    data->colors[pos - 1] = get_rgb(ft_atol(rgb[0]), ft_atol(rgb[1]), ft_atol(rgb[2]));
    ft_free_mtx(rgb);
    ft_free_mtx(splitted);
    return (1);
}

int check_texture(t_data *data, char *line, int rgb)
{
    char    **splitted;
    char    *texture_path;
    int     fd;

    splitted = ft_split(line, ' ');
    if (!splitted || !splitted[0])
        error_msg(INVALID_TEXTURE_TYPE);
    if (ft_strlen(splitted[0]) < 1 || ft_strlen(splitted[0]) > 2)
        error_msg(INVALID_TEXTURE_TYPE);
    if (!splitted[1] || ft_mtxlen(splitted) > 3)
        error_msg(INVALID_TEXTURE);
    if (rgb)
        return (check_rgb(data, splitted, rgb));
    texture_path = ft_strtrim(splitted[1], "\n");
    fd = open(texture_path, O_RDONLY);
    if (fd == -1)
        error_msg(INVALID_TEXTURE);
    close(fd);
    free(texture_path);
    ft_free_mtx(splitted);
    return (1);
}