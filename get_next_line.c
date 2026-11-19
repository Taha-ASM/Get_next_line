/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tait-si <tait-si@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 15:22:39 by tait-si           #+#    #+#             */
/*   Updated: 2026/11/19 14:41:57 by tait-si          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

char	*ft_read(int fd, char *buffer)
{
	char	*str;
	char	*tmp;
	int		count;

	count = 1;
	while (whereareyou(buffer) && count != 0)
	{
		str = malloc(BUFFER_SIZE + 1);
		if (!str)
			return (free(buffer), NULL);
		count = read(fd, str, BUFFER_SIZE);
		if (count < 0)
			return (free(str), NULL);
		str[count] = '\0';
		tmp = ft_strjoin(buffer, str);
		if (!tmp)
			return (free(str), NULL);
		free(str);
		free(buffer);
		buffer = tmp;
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &buffer, 0) < 0)
		return (NULL);
	buffer = ft_read(fd, buffer);
	if (!buffer || buffer[0] == '\0')
		return (free(buffer), buffer = NULL, NULL);
	line = ft_get_line(buffer);
	tmp = ft_get_reminder(buffer);
	free(buffer);
	buffer = tmp;
	printf("buffer -> [%s]\n", buffer);
	return (line);
}
