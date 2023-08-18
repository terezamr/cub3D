#include "../inc/cub3D.h"

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
