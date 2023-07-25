/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:02:51 by mvicente          #+#    #+#             */
/*   Updated: 2023/07/06 16:28:56 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

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
	
	dist = malloc(sizeof(double) * 4);
    //dist[0] = sqrt((ray[1] * ray[1]) / (ray[0] * ray[0]) + 1);
    //dist[1] = sqrt((ray[0] * ray[0]) / (ray[1] * ray[1]) + 1);
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
	if (ray[0] < 0 && dist[0] > 0)
	{
		data->step_x = -1;
		dist[2] = (data->posX - map[0]) * dist[0]; 
	}
	else if (dist[0] > 0)
	{
		data->step_x = 1;
		dist[2] = (map[0] + 1 - data->posX) * dist[0];
	}
	else
	{
		data->step_x = 0;
		dist[2] = INF;
	}
	if (ray[1] < 0 && dist[1] > 0)
	{
		data->step_y = -1;
		dist[3] = (data->posY - map[1]) * dist[1];
	}
	else if (dist[1] > 0)
	{
		data->step_y = 1;
		dist[3] = (map[1] + 1 - data->posY) * dist[1];
	}
	else
	{
		data->step_y = 0;
		dist[3] = INF;
	}
	return (dist);
}

int	*get_step(int *step, double *ray, double *dist)
{
	if (ray[0] < 0 && dist[0] > 0)
		step[0] = -1;
	else if (dist[0] > 0)
		step[0] = 1;	
	else
		step[0] = 0;
	if (ray[1] < 0 && dist[1] > 0)
		step[1] = -1;
	else if (dist[1] > 0)
		step[1] = 1;
	else
		step[1] = 0;
	return (step);
}

void    calculations(t_data *data)
{
    double	x;
	double	*ray;
	double	*dist;
	int		*map;

    x = 0;
	data->angle_r = (data->angle_d * PI) / 180;
    while (x < WINDOW_WIDTH - 1)
	{
        data->hit = 0;
		map = malloc(sizeof(int) * 2);
		map[0] = (int)data->posX;
		map[1] = (int)data->posY;
		ray = get_ray(data, x);
		dist = get_dist(data, map, ray);
		while (data->hit == 0)
		{
			if (dist[2] < dist[3])
			{
				dist[2] = dist[2] + dist[0];
				map[0] = map[0] + data->step_x;
				data->side = 0;
			}
			else
			{
				dist[3] = dist[3] + dist[1];
				map[1] = map[1] + data->step_y;
				data->side = 1;
			}
			if ((data->map[map[0]][map[1]]) == '1')
				data->hit = 1;
		}
		if (x == 0)
		{
			if (data->side == 0)
				data->ray_distance = (dist[2] - dist[0]);
			else
				data->ray_distance = (dist[3] - dist[1]);
			data->camp = 2 * (float)data->ray_distance * sin(0.66);
			printf("camp %f\n", data->camp);
		}
        drawing(x, data, dist, ray);
		free(ray);
		free(map);
		free(dist);
		x++;
	}
}
