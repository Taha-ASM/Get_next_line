/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tait-si <tait-si@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 12:37:44 by tait-si           #+#    #+#             */
/*   Updated: 2026/11/19 14:37:42 by tait-si          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read(int fd, char *buffer)
{
	char	*str;
	char	*tmp;
	ssize_t		count;

	count = 1;
	while (is_line(buffer) && count != 0)
	{
		str = malloc((size_t)BUFFER_SIZE + 1);
		if (!str)
			return (free(buffer), NULL);
		count = read(fd, str, BUFFER_SIZE);
		if (count < 0)
			return (free(str), free(buffer), NULL);
		str[count] = '\0';
		tmp = ft_strjoin(buffer, str);
		if (!tmp)
			return (free(buffer), free(str), NULL);
		free(str);
		free(buffer);
		buffer = tmp;
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line;
	char		*tmp;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = ft_read(fd, buffer[fd]);
	if (!buffer[fd] || buffer[fd][0] == '\0')
		return (free(buffer[fd]), buffer[fd] = NULL, NULL);
	line = ft_get_line(buffer[fd]);
	tmp = ft_get_reminder(buffer[fd]);
	free(buffer[fd]);
	buffer[fd] = tmp;
	return (line);
}
