/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgarc4 <davgarc4@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 13:26:03 by davgarc4          #+#    #+#             */
/*   Updated: 2026/03/14 22:51:05 by davgarc4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char	*reader(int fd)
{
	char	*buffer;
	int		bytes;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes = read(fd, buffer, BUFFER_SIZE);
	if (bytes <= 0)
	{
		free(buffer);
		return (NULL);
	}
	buffer[bytes] = '\0';
	return (buffer);
}

static char	*join_saved_buffer(char *saved, char *buffer)
{
	char	*tmp;

	tmp = ft_strjoin(saved, buffer);
	free(saved);
	free(buffer);
	return (tmp);
}

static char	*handle_eof(char **saved)
{
	char	*result;

	if (!ft_strlen(*saved))
	{
		free(*saved);
		*saved = NULL;
		return (NULL);
	}
	result = ft_strdup(*saved, '\0');
	free(*saved);
	*saved = NULL;
	return (result);
}

static char	*extract_line(char **saved, char *ptr)
{
	char	*result;
	char	*tmp;

	*ptr = '\0';
	result = ft_strdup(*saved, SEPARATOR);
	if (!result)
		return (free(*saved), *saved = NULL, NULL);
	tmp = ft_strdup(ptr + 1, '\0');
	free(*saved);
	if (!tmp)
	{
		*saved = NULL;
		return (result);
	}
	*saved = tmp;
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*saved;
	char		*buffer;
	char		*ptr;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (free(saved), saved = NULL, NULL);
	if (!saved)
	{
		saved = reader(fd);
		if (!saved)
			return (NULL);
	}
	ptr = ft_strchr(saved, SEPARATOR);
	while (!ptr)
	{
		buffer = reader(fd);
		if (!buffer)
			return (handle_eof(&saved));
		saved = join_saved_buffer(saved, buffer);
		if (!saved)
			return (NULL);
		ptr = ft_strchr(saved, SEPARATOR);
	}
	return (extract_line(&saved, ptr));
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
