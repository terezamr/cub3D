/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 18:27:10 by rade-sar          #+#    #+#             */
/*   Updated: 2023/08/29 13:26:52 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen1(const char *s)
{
	size_t	len;

	if (!s || s[0] == 0)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	check_n(char *string, int *flag)
{
	int	a;

	a = -1;
	while (string[++a] != 0)
	{
		if (string[a] == '\n')
		{
			*flag = 1;
			return (a);
		}
	}
	return (a);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char		*ptr;
	size_t		i;

	i = 0;
	ptr = malloc(size * nmemb);
	if (!ptr)
		return (NULL);
	while (i < nmemb * size)
	{
		ptr[i] = '\0';
		i++;
	}
	return ((void *)ptr);
}

int	get_count(char **temp)
{
	int		count;

	count = 0;
	if (temp != (void *)0)
		count = (int)ft_strlen1(*temp);
	return (count);
}