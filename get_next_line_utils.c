/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrema <hrema@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 09:50:01 by hrema             #+#    #+#             */
/*   Updated: 2020/05/21 16:30:36 by hrema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	c = (unsigned char)c;
	while (*s != '\0')
	{
		if (*s == c)
			return ((char *)(s));
		s++;
	}
	if (*s == c)
		return ((char *)(s));
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	char	*duplicat;
	int		size;

	size = 0;
	while (s[size] != '\0')
		size++;
	if (!(duplicat = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	size = 0;
	while (s[size] != '\0')
	{
		duplicat[size] = s[size];
		size++;
	}
	duplicat[size] = '\0';
	return (duplicat);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	const char	*ptr_s1;
	const char	*ptr_s2;
	char		*new_line;
	int			len_new_line;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	len_new_line = ft_strlen(s1) + ft_strlen(s2);
	ptr_s1 = s1;
	ptr_s2 = s2;
	if (!(new_line = (char *)malloc(sizeof(char) * (len_new_line + 1))))
		return (NULL);
	len_new_line = 0;
	while (*ptr_s1 != '\0')
		new_line[len_new_line++] = *ptr_s1++;
	free((char *)s1);
	while (*ptr_s2 != '\0')
		new_line[len_new_line++] = *ptr_s2++;
	new_line[len_new_line] = '\0';
	return (new_line);
}
