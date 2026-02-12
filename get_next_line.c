/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgarc4 <davgarc4@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 13:26:03 by davgarc4          #+#    #+#             */
/*   Updated: 2026/02/12 21:00:31 by davgarc4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char	*reader(int fd)
{
	char		*buffer;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (read(fd, buffer, BUFFER_SIZE) <= 0)
		return (NULL);
	buffer[BUFFER_SIZE] = '\0';
	return (buffer);
}

char *get_next_line(int fd)
{
	static char	*saved;
	char		*buffer;
	char		*tmp;
	char		*ptr;
	char		*result;
	
	if (!saved)
	{
		if ((buffer = reader(fd)))
			saved = buffer;
		else
			return (NULL);
	}
	else
	{
		buffer = saved;
	}
	while(!(ptr = ft_strchr(saved, SEPARATOR)))
	{
		if ((buffer = reader(fd)))
		{
			tmp = saved;
			saved = ft_strjoin(saved, buffer);
			free(tmp);
		}
		else
		{
			result = ft_strdup(saved, '\0');
			free(saved);
			saved = NULL;
			return (result);
		}
	}
	*ptr = '\0';
	result = ft_strdup(saved , SEPARATOR);
	saved = ft_strdup(&ptr[1], '\0');
	free(buffer);
	return (result);
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