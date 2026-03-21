/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgarc4 <davgarc4@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 13:26:03 by davgarc4          #+#    #+#             */
/*   Updated: 2026/03/21 22:52:49 by davgarc4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

char	*saved_join(char *saved, char *buffer)
{
	char	*tmp;

	if (!saved)
		return (ft_strdup(buffer, '\0'));
	tmp = ft_strjoin(saved, buffer);
	free(saved);
	return (tmp);
}

char	*ft_substr(char *s, int start, size_t len)
{
	char	*ptr;
	size_t	size;
	size_t	idx;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	if (start < 0 || (size_t)start >= size)
		return (ft_strdup("", '\0'));
	if (len > size - start)
		len = size - start;
	ptr = malloc(len + 1);
	if (!ptr)
		return (NULL);
	idx = 0;
	while (idx < len)
	{
		ptr[idx] = s[start + idx];
		idx++;
	}
	ptr[idx] = '\0';
	return (ptr);
}

char	*read_and_join(int fd, char *saved)
{
	char	*buffer;
	int		bytes;

	while (!saved || !ft_strchr(saved, '\n'))
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
		{
			free(saved);
			return (NULL);
		}
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes <= 0)
			return (handle_read_result(bytes, saved, buffer));
		buffer[bytes] = '\0';
		saved = saved_join(saved, buffer);
		free(buffer);
		if (!saved)
			return (NULL);
	}
	return (saved);
}

char	*extract_line_static(char **saved)
{
	char	*line;
	char	*rest;
	char	*ptr;

	if (!*saved || **saved == '\0')
	{
		free(*saved);
		*saved = NULL;
		return (NULL);
	}
	ptr = ft_strchr(*saved, '\n');
	if (ptr)
	{
		line = ft_substr(*saved, 0, ptr - *saved + 1);
		rest = ft_strdup(ptr + 1, '\0');
	}
	else
	{
		line = ft_strdup(*saved, '\0');
		rest = NULL;
	}
	free(*saved);
	*saved = rest;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*saved;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	saved = read_and_join(fd, saved);
	if (!saved)
		return (NULL);
	return (extract_line_static(&saved));
}
