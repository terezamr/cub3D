/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:02:51 by mvicente          #+#    #+#             */
/*   Updated: 2023/06/29 16:04:04 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

double	*get_ray(t_data *data, double x)
{
	double	*ray;
	double	cameraX;
	
	ray = malloc(sizeof(double) * 2);
	cameraX = 2 * x / (double)WINDOW_WIDTH - 1;
    ray[0] = data->dirX + data->planeX * cameraX;
    ray[1] = data->dirY + data->planeY * cameraX;
	return (ray);
}

/*dist: dist beetween x axis, dist between y axis, dist
between pos and next x axis, dist between pos and next y axis*/
double	*get_dist(t_data *data, int *map, double *ray)
{
	double	*dist;
	//double	ray_len;
	
	dist = malloc(sizeof(double) * 4);
	//ray_len = sqrt((ray[0] * ray[0]) + (ray[1] * ray[1]));
    if (ray[0] != 0)
        dist[0] = fabs(1 / ray[0]);
    else
        dist[0] = -1;    
    if (ray[1] != 0)
        dist[1] = fabs(1 / ray[1]);
    else
	{
        dist[1] = -1; 
	}
	if (ray[0] < 0)
		dist[2] = (data->posX - map[0]) * dist[0]; 
	else
		dist[2] = (map[0] + 1 - data->posX) * dist[0];
	if (ray[1] < 0)
		dist[3] = (data->posY - map[1]) * dist[1];
	else
		dist[3] = (map[1] + 1 - data->posY) * dist[1];
	return (dist);
}

int	*get_step(int *step, double *ray)
{
	if (ray[0] < 0)
		step[0] = -1;
	else
		step[0] = 1;	
	if (ray[1] < 0)
		step[1] = -1;
	else
		step[1] = 1;
	return (step);
}

void    calculations(t_data *data)
{
    double	x;
	double	*ray;
	double	*dist;
	int		*map;
	int		*step;
	int		side;

    step = malloc(sizeof(int) * 2);
    x = 0;
    side = 0;
    while (x < WINDOW_WIDTH - 1)
	{
        data->hit = 0;
		map = malloc(sizeof(int) * 2);
		map[0] = (int)data->posX;
		map[1] = (int)data->posY;
		ray = get_ray(data, x);
		dist = get_dist(data, map, ray);
		step = get_step(step, ray);
		while (data->hit == 0)
		{
			if (dist[2] < dist[3])
			{
				dist[2] = dist[2] + dist[0];
				map[0] = map[0] + step[0];
				side = 0;
			}
			else
			{
				dist[3] = dist[3] + dist[1];
				map[1] = map[1] + step[1];
				side = 1;
			}
			if (data->world_map[map[0]][map[1]] == 1)
				data->hit = 1;
		}
        drawing(x, data, side, dist);
		free(map);
		x++;
	}
	free(step);
}
