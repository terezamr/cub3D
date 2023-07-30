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
	double	camerax;

	ray = malloc(sizeof(double) * 2);
	camerax = 2 * x / (double)WINDOW_WIDTH - 1;
	ray[0] = data->dirX + data->planeX * camerax;
	ray[1] = data->dirY + data->planeY * camerax;
	return (ray);
}

double *dist_one(double *ray)
{
	double	*dist;

	dist = malloc(sizeof(double) * 4);
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
	return (dist);
}

double *dist_two(t_data *data, double *ray, double *dist)
{
	if (ray[0] < 0 && dist[0] > 0)
	{
		data->step_x = -1;
		dist[2] = (data->posX - data->map_c[0]) * dist[0]; 
	}
	else if (dist[0] > 0)
	{
		data->step_x = 1;
		dist[2] = (data->map_c[0] + 1 - data->posX) * dist[0];
	}
	else
	{
		data->step_x = 0;
		dist[2] = INF;
	}
	return (dist);
}

/*dist: dist beetween x axis, dist between y axis, dist
between pos and next x axis, dist between pos and next y axis*/
double	*get_dist(t_data *data, double *ray)
{
	double	*dist;
	
    //dist[0] = sqrt((ray[1] * ray[1]) / (ray[0] * ray[0]) + 1);
    //dist[1] = sqrt((ray[0] * ray[0]) / (ray[1] * ray[1]) + 1);
	dist = dist_one(ray);
	dist = dist_two(data, ray, dist);
	if (ray[1] < 0 && dist[1] > 0)
	{
		data->step_y = -1;
		dist[3] = (data->posY - data->map_c[1]) * dist[1];
	}
	else if (dist[1] > 0)
	{
		data->step_y = 1;
		dist[3] = (data->map_c[1] + 1 - data->posY) * dist[1];
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

    x = 0;
    while (x < WINDOW_WIDTH - 1)
	{
        data->hit = 0;
		data->map_c[0] = (int)data->posX;
		data->map_c[1] = (int)data->posY;
		ray = get_ray(data, x);
		dist = get_dist(data, ray);
		while (data->hit == 0)
		{
			if (dist[2] < dist[3])
			{
				dist[2] = dist[2] + dist[0];
				data->map_c[0] = data->map_c[0] + data->step_x;
				data->side = 0;
			}
			else
			{
				dist[3] = dist[3] + dist[1];
				data->map_c[1] = data->map_c[1] + data->step_y;
				data->side = 1;
			}
			if ((data->map[data->map_c[0]][data->map_c[1]]) == '1')
				data->hit = 1;
		}
        drawing(x, data, dist, ray);
		free(ray);
		free(dist);
		x++;
	}
}
