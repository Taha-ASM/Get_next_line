/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tait-si <tait-si@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 12:37:44 by tait-si           #+#    #+#             */
/*   Updated: 2026/11/19 14:37:42 by tait-si          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	is_line(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strjoin(char *buffer, char *str)
{
	int		i;
	int		x;
	char	*arr;

	i = 0;
	x = 0;
	if (!buffer)
		buffer = "";
	arr = malloc(ft_strlen(buffer) + ft_strlen(str) + 1);
	if (!arr)
		return (NULL);
	while (buffer && buffer[i])
		arr[x++] = buffer[i++];
	i = 0;
	while (str[i])
		arr[x++] = str[i++];
	arr[x] = '\0';
	return (arr);
}

char	*ft_get_line(char *buffer)
{
	int		i;
	int		x;
	char	*arr;

	i = 0;
	x = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	arr = malloc(i + 1);
	if (!arr)
		return (NULL);
	while (x < i)
	{
		arr[x] = buffer[x];
		x++;
	}
	arr[x] = '\0';
	return (arr);
}

char	*ft_get_reminder(char *buffer)
{
	int		i;
	int		x;
	char	*arr;

	i = 0;
	x = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	arr = malloc(ft_strlen(buffer) - i + 1);
	if (!arr)
		return (NULL);
	while (buffer[i])
		arr[x++] = buffer[i++];
	arr[x] = '\0';
	return (arr);
}
