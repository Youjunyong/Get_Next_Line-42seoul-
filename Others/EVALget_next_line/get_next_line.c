/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woolee <woolee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 09:42:02 by woolee            #+#    #+#             */
/*   Updated: 2021/04/28 09:50:34 by woolee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strret(char **strmem, int fd, char *nlpos, char **line)
{
	char	*temp;

	if (nlpos != NULL)
	{
		*nlpos = '\0';
		*line = ft_strdup(strmem[fd]);
		temp = ft_strdup(nlpos + 1);
		free(strmem[fd]);
		strmem[fd] = temp;
		return (1);
	}
	if (strmem[fd] != NULL)
	{
		*line = ft_strdup(strmem[fd]);
		free(strmem[fd]);
		strmem[fd] = NULL;
	}
	return (0);
}

int		ft_freeall(char *strbuf)
{
	free(strbuf);
	return (-1);
}

int		get_next_line(int fd, char **line)
{
	static char	*strmem[OPEN_MAX];
	char		*nlpos;
	char		*strbuf;
	char		*temp;
	ssize_t		rdsize;

	rdsize = 0;
	if (fd < 0 || fd > OPEN_MAX || !line || BUFFER_SIZE < 1)
		return (-1);
	if ((strbuf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))) < 0)
		return (-1);
	if (strmem[fd] == NULL)
		strmem[fd] = ft_strdup("");
	while (((nlpos = ft_strchr(strmem[fd], '\n')) == 0) &&
			((rdsize = read(fd, strbuf, BUFFER_SIZE)) > 0))
	{
		strbuf[rdsize] = '\0';
		temp = ft_strjoin(strmem[fd], strbuf);
		free(strmem[fd]);
		strmem[fd] = temp;
	}
	if (rdsize < 0)
		return (ft_freeall(strbuf));
	free(strbuf);
	return (ft_strret(strmem, fd, nlpos, line));
}
