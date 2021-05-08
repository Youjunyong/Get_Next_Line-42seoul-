/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyou <juyou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 17:02:54 by juyou             #+#    #+#             */
/*   Updated: 2021/05/08 13:09:51 by juyou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int				find_new_line(char *keep)
{
	int			i;

	i = 0;
	while (keep[i])
	{
		if (keep[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int				split_line(char **keep, char **line, int target)
{
	char		*temp;
	int			len;

	(*keep)[target] = '\0';
	*line = ft_strdup(*keep);
	len = ft_strlen(*keep + target + 1);
	if (len == 0)
	{
		free(*keep);
		*keep = 0;
		return (1);
	}
	temp = ft_strdup(*keep + target + 1);
	free(*keep);
	*keep = temp;
	return (1);
}

int				ret_eof(char **keep, char **line)
{
	int			target;

	if (*keep && (target = find_new_line(*keep)) >= 0)
		return (split_line(keep, line, target));
	else if (*keep)
	{
		*line = *keep;
		*keep = 0;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}

int				get_next_line(int fd, char **line)
{
	static char	*keep[OPEN_MAX];
	char		buf[BUFFER_SIZE + 1];
	int			read_size;
	int			target;

	if (fd < 0 || fd > OPEN_MAX || !line || BUFFER_SIZE <= 0)
		return (-1);
	while ((read_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_size] = '\0';
		keep[fd] = ft_strjoin(keep[fd], buf);
		if ((target = find_new_line(keep[fd])) >= 0)
			return (split_line(&keep[fd], line, target));
	}
	if (read_size < 0)
		return (-1);
	return (ret_eof(&keep[fd], line));
}
