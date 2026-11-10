/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tait-si <tait-si@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 15:22:39 by tait-si           #+#    #+#             */
/*   Updated: 2026/11/10 14:38:49 by tait-si          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *buff)
{
	char	*str;
	char	*tmp;
	int		count;

	str = malloc(BUFFER_SIZE + 1);
	if (str == NULL)
		return (NULL);
	count = 1;
	while ((!buff || !ft_strchr(buff, '\n')) && count != 0) //! need to understand this condition
	{
		count = read(fd, str, BUFFER_SIZE);
		if (count == -1)
			return (free(str), NULL);
		str[count] = '\0';
		tmp = ft_strjoin(buff, str);
		if (tmp == NULL)
			return (NULL);
		buff = tmp;
	}
	free(str);
	return (buff);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = ft_read(fd, buff);
	if (buff == NULL || buff[0] == '\0')
	{
		free(buff);
		buff = NULL;
		return (NULL);
	}
	line = ft_get_line(buff);
	buff = ft_get_reminder(buff);
	return (line);
}

int	main(void)
{
	int fd = open("file.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	char *line;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}