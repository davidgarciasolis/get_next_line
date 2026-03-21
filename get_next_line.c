/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgarc4 <davgarc4@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 13:26:03 by davgarc4          #+#    #+#             */
/*   Updated: 2026/03/21 19:45:12 by davgarc4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char	*ft_substr(char *s, int start, size_t len)
{
	size_t	size;
	char	*ptr;

	if (len == 0 || start >= ft_strlen(s))
	{
		ptr = malloc(1);
		if (!ptr)
			return (NULL);
		ptr[0] = '\0';
		return (ptr);
	}
	size = ft_strlen(&s[start]);
	if (size < len)
		ptr = malloc(size + 1);
	else
		ptr = malloc(len + 1);
	if (!ptr)
		return (NULL);
	if (start >= ft_strlen(s))
		ft_strlcpy(ptr, "", size);
	else if (size < len)
		ft_strlcpy(ptr, &s[start], size + 1);
	else
		ft_strlcpy(ptr, &s[start], len + 1);
	return (ptr);
}

char	*read_and_join(int fd, char *saved)
{
	char	*buffer;
	int		bytes;
	char 	*tmp;
	
	while (!saved || !ft_strchr(saved, '\n'))
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return (free(saved), NULL);
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes <= 0)
			return (free(buffer), bytes < 0 ? free(saved), NULL : saved);
		buffer[bytes] = '\0';
		if (!saved)
			saved = ft_strdup(buffer, '\0');
		else
		{
			tmp = ft_strjoin(saved, buffer);
			free(saved);
			saved = tmp;
		}
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
	int		len;

	if (!*saved || **saved == '\0')
		return (free(*saved), *saved = NULL, NULL);
	ptr = ft_strchr(*saved, '\n');
	if (ptr)
	{
		len = ptr - *saved + 1;
		line = ft_substr(*saved, 0, len);
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
/*
int main(int argc, char **argv)
{
	int fd;
	char	*ptr;

	if (argc != 2)
	{
		printf("Uso: %s <archivo>\n", argv[0]);
		return (1);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		return (1);
	}

	while ((ptr = get_next_line(fd)))
	{
		printf("%s", ptr);
		free(ptr);
	}

	close(fd);
	return (0);
}

*/