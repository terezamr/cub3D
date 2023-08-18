#include "../inc/cub3D.h"

int check_map_edges(char **map, t_point p, int max_x, int max_y)
{
	if (p.y == 0 && (map[p.y][p.x] == '1' || ft_isspace(map[p.y][p.x])))
		return (1);
	if (p.y == max_y && (map[p.y][p.x] == '1' || ft_isspace(map[p.y][p.x])))
		return (1);
	if (p.x == 0 && (map[p.y][p.x] == '1' || ft_isspace(map[max_y - 1][p.x])))
		return (1);
	if (p.x == max_x - 1 && (map[p.y][p.x] == '1' || ft_isspace(map[p.y][p.x])))
		return (1);
	return (0);
}

int	is_map_char(char c)
{
	if (c && !ft_isspace(c))
		return (1);
	return (0);
}

int	is_closed(char **map, t_point p, int max_x, int max_y)
{
	int	adjacent;

	adjacent = 0;
	if (p.x == 0 || p.y == 0 || p.x == 0 || p.x == max_x - 1)
		return (check_map_edges(map, p, max_x, max_y));
	else
	{
		if (map[p.y - 1][p.x] && is_map_char(map[p.y - 1][p.x])
			&& map[p.y - 1][p.x - 1] && is_map_char(map[p.y - 1][p.x - 1])
			&& map[p.y - 1][p.x + 1] && is_map_char(map[p.y - 1][p.x + 1]))
			adjacent++;
		if (map[p.y + 1] && map[p.y + 1][p.x] && is_map_char(map[p.y + 1][p.x])
			&& map[p.y + 1][p.x - 1] && is_map_char(map[p.y + 1][p.x - 1])
			&& map[p.y + 1][p.x + 1] && is_map_char(map[p.y + 1][p.x + 1]))
			adjacent++;
		if (map[p.y][p.x - 1] && is_map_char(map[p.y][p.x - 1]))
			adjacent++;
		if (map[p.y][p.x + 1] && is_map_char(map[p.y][p.x + 1]))
			adjacent++;
		if (adjacent == 4)
			return (1);
	}
	return (0);
}

void	check_orientation(t_data *data, char p, int x, int y)
{
	if (p == 'N' || p == 'E'
		|| p == 'W' || p == 'S')
	{
		if (data->letter == 0)
		{
			data->letter = p;
			data->posX = y;
			data->posY = x;
		}
		else
			error_msg(PLAYER_ERROR);
	}
}

void    check_map(t_data *data)
{
    int x;
    int y;
    int width;

    y = -1;
    if (ft_mtxlen(data->map) < 3)
        error_msg(INVALID_MAP);   
    while (++y != data->map_height)
    {
        x = -1;
        width = ft_strlen(data->map[y]);
        while (data->map[y][++x])
        {
            if (data->map[y][x] != '1' && !ft_isspace(data->map[y][x])
                && !is_closed(data->map, (t_point){x,y}, width, data->map_height))
                error_msg(INVALID_BORDER);
			check_orientation(data, data->map[y][x], x, y);
		}
    }
	if (data->letter == 0)
		error_msg(PLAYER_ERROR);
}

