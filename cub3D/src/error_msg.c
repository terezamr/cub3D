/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 10:38:33 by rade-sar          #+#    #+#             */
/*   Updated: 2023/08/29 17:51:28 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	free_vars(t_data *data)
{
	int	i;

	free(data->colors);
	free(data->map_c);
	if (data->textures[0])
		free(data->textures[0]);
	if (data->textures[1])
		free(data->textures[1]);
	if (data->textures[2])
		free(data->textures[2]);	
	if (data->textures[3])
		free(data->textures[3]);
	free(data->textures);
	i = 0;
	while (data->map && data->map[i])
		free(data->map[i++]);
	if (data->map)
		free(data->map);
}

void	error_msg(t_data *data, char *message)
{
	free_vars(data);
	printf("%s%s%s\n", RED, "Error", RESET);
	printf("%s\n", message);
	exit(1);
}
