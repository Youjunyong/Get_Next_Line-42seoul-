/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyou <juyou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 17:02:54 by juyou             #+#    #+#             */
/*   Updated: 2021/05/05 18:41:50 by juyou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	find_new_line(char *bu)
{
	int	i;
	
	i = 0;
	while (bu[i])
	{
		if (bu[i] == '\n')
			return (i);
		i++;
	}
	return (-1);

}

int	split_line(char **bu, char **line, int cut_idx)
{
	char	*temp;
	int		len;
	
	(*bu)[cut_idx] = '\0';
	*line = ft_strdup(*bu);
	len = ft_strlen(*bu + cut_idx + 1);
	
	if (len == 0)
	{
		free(*bu);
		*bu = 0;
		return (1);
	}
	temp = ft_strdup(*bu + cut_idx + 1);
	free(*bu);
	*bu = temp;
	return (1);
}
int					return_all(char **bu, char **line)
{
	int		cut_idx;

	if (*bu && (cut_idx = find_new_line(*bu)) >= 0)
		return (split_line(bu, line, cut_idx));
	else if (*bu)
	{
		*line = *bu;
		*bu = 0;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}


int	get_next_line(int fd, char **line)
{
	static char	*bu[OPEN_MAX];
	char		buf[BUFFER_SIZE + 1];
	int			read_size;
	int			cut_idx;

	if ((fd < 0) || !line || (BUFFER_SIZE <= 0))
	if (fd < 0 || fd > OPEN_MAX || !line || BUFFER_SIZE <= 0)

		return (-1);
	while ((read_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_size] = '\0';
		bu[fd] = ft_strjoin(bu[fd], buf);
		if ((cut_idx = find_new_line(bu[fd])) >= 0)
			return (split_line(&bu[fd], line, cut_idx));
	}

	if (read_size < 0)
		return (-1);

	return (return_all(&bu[fd], line));
}

