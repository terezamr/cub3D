/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <rade-sar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 10:38:33 by rade-sar          #+#    #+#             */
/*   Updated: 2023/08/24 10:44:49 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	free_vars(t_data *data)
{
	int	i;

	free(data->colors);
	free(data->map_c);
	i = 0;
	while (i != 4 && data->textures[i])
		free(data->textures[i++]);
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
