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

int check_rgb(char *line)
{
    char    **splitted;
    char    **rgb;
    char    *texture_path;
    char    *n;
    int     i;

    splitted = ft_split(line, ' ');
    if (!splitted || !splitted[0])
        error_msg(INVALID_TEXTURE_TYPE);
    if (ft_strlen(splitted[0]) < 1 || ft_strlen(splitted[0]) > 2)
        error_msg(INVALID_TEXTURE_TYPE);
    if (!splitted[1])
        error_msg(INVALID_TEXTURE);
    rgb = ft_split(splitted[1], ',');
    if (!rgb || !rgb[0] || !rgb[1] || !rgb[2])
        error_msg(INVALID_RGB);
    i = 0;
    while (i != 3)
    {
        n = ft_atoi();
    }
    ft_free_mtx(rgb);
    ft_free_mtx(splitted);
    return (1);
}

int check_texture(char *line)
{
    char    **splitted;
    char    *texture_path;
    int     fd;

    splitted = ft_split(line, ' ');
    if (!splitted || !splitted[0])
        error_msg(INVALID_TEXTURE_TYPE);
    if (ft_strlen(splitted[0]) < 1 || ft_strlen(splitted[0]) > 2)
        error_msg(INVALID_TEXTURE_TYPE);
    if (!splitted[1])
        error_msg(INVALID_TEXTURE);
    texture_path = ft_strtrim(splitted[1], "\n");
    fd = open(texture_path, O_RDONLY);
    if (fd == -1)
        error_msg(INVALID_TEXTURE);
    close(fd);
    free(texture_path);
    ft_free_mtx(splitted);
    return (1);
}