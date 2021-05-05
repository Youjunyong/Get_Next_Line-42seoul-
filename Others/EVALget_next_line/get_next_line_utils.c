/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woolee <woolee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 09:55:21 by woolee            #+#    #+#             */
/*   Updated: 2021/04/28 10:00:01 by woolee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	while (s[size] != '\0')
		size++;
	return (size);
}

char	*ft_strchr(const char *s, int c)
{
	while (1)
	{
		if (*s == ((char)c))
			return ((char *)s);
		if (*s == '\0')
			return ((char *)'\0');
		s++;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*start;

	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == (void *)0)
		return ((void *)0);
	start = str;
	while (*s1 != '\0')
		*str++ = *s1++;
	while (*s2 != '\0')
		*str++ = *s2++;
	*str = '\0';
	return (start);
}

char	*ft_strdup(char *s1)
{
	char	*str_ret;
	char	*str;
	size_t	size;

	size = ft_strlen(s1) + 1;
	str = (char *)malloc(sizeof(char) * size);
	if (str == NULL)
		return (NULL);
	str_ret = str;
	while (size--)
		*str++ = *s1++;
	return (str_ret);
}
