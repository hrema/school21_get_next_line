/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrema <hrema@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 11:40:14 by hrema             #+#    #+#             */
/*   Updated: 2020/05/21 15:39:50 by hrema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	filling_line(char **line, char **current_line, char *next_line)
{
	char		*temp;

	*next_line++ = '\0';
	temp = *current_line;
	if (!(*line = ft_strdup(*current_line)))
		return (-1);
	if (!(*current_line = ft_strdup(next_line)))
		return (-1);
	free(temp);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	int			r;
	static char	*current_line;
	char		*next_line;

	if (fd < 0 || !line || (read(fd, buf, 0) < 0))
		return (-1);
	while ((r = read(fd, buf, BUFFER_SIZE)))
	{
		buf[r] = '\0';
		if (!(current_line = ft_strjoin(current_line, buf)))
			return (-1);
		if ((next_line = ft_strchr(current_line, '\n')))
			return (filling_line(line, &current_line, next_line));
	}
	if (current_line && (next_line = ft_strchr(current_line, '\n')))
		return (filling_line(line, &current_line, next_line));
	if (current_line)
	{
		*line = current_line;
		current_line = NULL;
		return (0);
	}
	return (!(*line = ft_strdup("")) ? -1 : 0);
}
