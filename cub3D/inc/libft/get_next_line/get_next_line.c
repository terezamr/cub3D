/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 22:54:05 by gafreita          #+#    #+#             */
/*   Updated: 2023/08/29 18:44:44 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	fill_buffer(char *buffer, int len)
{
	int	i;
	int	remain_b;

	remain_b = BUFFER_SIZE - len;
	i = 0;
	while (buffer[i])
	{
		if (i < remain_b)
			buffer[i] = buffer[i + len];
		else
			buffer[i] = '\0';
		i++;
	}
}

char	*new_join(char *temp, char *buffer, int len)
{
	char	*new_temp;
	int		i;
	int		d;
	int		count;

	d = 0;
	if (!temp)
		temp = ft_calloc(1, 1);
	new_temp = NULL;
	count = get_count(&temp) + 1;
	new_temp = malloc(count + len + 1);
	if (!new_temp)
		return (NULL);
	i = -1;
	while (temp[++i] != 0)
		new_temp[i] = temp[i];
	while (d < len)
		new_temp[i++] = buffer[d++];
	new_temp[i] = '\0';
	fill_buffer(buffer, len);
	free(temp);
	return (new_temp);
}

char	*get_line_aux(char *buffer, char *temp, int *flag, int fd)
{
	int	r;
	int	len;

	while (1)
	{
		r = read(fd, buffer, BUFFER_SIZE);
		if (r == 0 && !buffer[0])
		{
			break ;
		}
		len = check_n(buffer, flag);
		temp = new_join(temp, buffer, len + 1);
		if (*flag == 1)
			break ;
	}
	return (temp);
}

char	*get_next_line(int fd)
{
	int			flag;
	int			len;
	char		*temp;
	static char	buffer[BUFFER_SIZE + 1];

	flag = 0;
	temp = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		buffer[0] = 0;
		return (0);
	}
	if (buffer[0])
	{
		len = check_n(buffer, &flag);
		temp = new_join(temp, buffer, len + 1);
		if (flag == 1)
			return (temp);
	}
	temp = get_line_aux(buffer, temp, &flag, fd);
	return (temp);
}
