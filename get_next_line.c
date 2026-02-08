/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgarc4 <davgarc4@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 13:26:03 by davgarc4          #+#    #+#             */
/*   Updated: 2026/02/08 16:32:43 by davgarc4         ###   ########.fr       */
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
	char		*ptr;
	char		*result;
	
	if (!saved)
		buffer =  reader(fd);
	else
		buffer = saved;
	while(!(ptr = ft_strchr(buffer, '\n')))
	{
		if ((buffer = reader(fd)))
		{
			saved = ft_strjoin(saved, buffer);
			buffer = saved;
		}
		else
		{
			return (NULL);
		}
	}
	*ptr = '\0';
	result = ft_strdup(buffer);
	saved = ft_strdup(&ptr[1]);
	free(buffer);
	return (result);
}

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
		printf("%s\n", ptr);
		free(ptr);
	}

	close(fd);
	return (0);
}
