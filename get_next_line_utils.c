/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tait-si <tait-si@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 12:37:44 by tait-si           #+#    #+#             */
/*   Updated: 2026/11/10 14:43:18 by tait-si          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	size_t	len1;
	char	*arr;

	len1 = 0;
	if (s1)
		len1 = ft_strlen(s1);
	arr = malloc(ft_strlen(s2) + len1 + 1);
	if (arr == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i])
		arr[j++] = s1[i++];
	i = 0;
	while (s2[i])
		arr[j++] = s2[i++];
	arr[j] = '\0';
	free(s1);
	return (arr);
}

char	*ft_strchr(char *s1, int c)
{
	int	i;

	if (!s1)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		if (s1[i] == (char)c)
			return (&s1[i]);
		i++;
	}
	if (s1[i] == (char)c)
		return (&s1[i]);
	return (NULL);
}

char	*ft_get_line(char *str)
{
	int		i;
	int		j;
	char	*arr;

	i = 0;
	j = 0;
	if (str == NULL || str[0] == '\0')
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	i++;
	arr = malloc(i + 1);
	if (arr == NULL)
		return (NULL);
	while (j < i)
	{
		arr[j] = str[j];
		j++;
	}
	arr[j] = '\0';
	return (arr);
}

char	*ft_get_reminder(char *s)
{
	int		i;
	int		j;
	char	*reminder;

	i = 0;
	j = 0;
	while (s[i] && s[i] != '\n')
		i++;
	i++;
	reminder = malloc(ft_strlen(s) - i + 1);
	if (reminder == NULL)
		return (free(s), NULL);
	while (s[i])
		reminder[j++] = s[i++];
	reminder[j] = '\0';
	free(s);
	return (reminder);
}
