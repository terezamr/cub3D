#include "../inc/cub3D.h"

int ft_isspace(int c)
{
	c = (unsigned char)c;
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == ' ')
		return (1);
	return (0);
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

void	vars_init2(t_data *data)
{
	int	i;

	i = 0;
	while (i != 4)
		data->textures[i++] = 0;
	i = 0;
	while (i != 2)
	{
		data->map_c[i] = 0;
		data->colors[i++] = -1;
	}
}

void	vars_init(t_data *data)
{
	data->mlx = 0;
	data->win = 0;
	data->distance = 0;
	data->height = 0;
	data->start = 0;
	data->end = 0;
	data->hit = 0;
	data->step_x = 0;
	data->step_y = 0;
	data->side = -1;
	data->letter = 0;
	data->map_c = malloc(sizeof(int) * 2);
	data->textures = malloc(sizeof(char *) * 4);
	data->colors = malloc(sizeof(int) * 2);
	vars_init2(data);
}