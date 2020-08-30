/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrema <hrema@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 16:06:57 by hrema             #+#    #+#             */
/*   Updated: 2020/05/21 16:56:40 by hrema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	filling_line(char **line, char **array_fd, char *next_line)
{
	char		*temp;

	*next_line++ = '\0';
	temp = *array_fd;
	if (!(*line = ft_strdup(*array_fd)))
		return (-1);
	if (!(*array_fd = ft_strdup(next_line)))
		return (-1);
	free(temp);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	int			r;
	static char	*array_fd[8192];
	char		*next_line;

	if (fd < 0 || !line || (read(fd, buf, 0) < 0))
		return (-1);
	while ((r = read(fd, buf, BUFFER_SIZE)))
	{
		buf[r] = '\0';
		if (!(array_fd[fd] = ft_strjoin(array_fd[fd], buf)))
			return (-1);
		if ((next_line = ft_strchr(array_fd[fd], '\n')))
			return (filling_line(line, &array_fd[fd], next_line));
	}
	if (array_fd[fd] && (next_line = ft_strchr(array_fd[fd], '\n')))
		return (filling_line(line, &array_fd[fd], next_line));
	if (array_fd[fd])
	{
		*line = array_fd[fd];
		array_fd[fd] = NULL;
		return (0);
	}
	return (!(*line = ft_strdup("")) ? -1 : 0);
}
