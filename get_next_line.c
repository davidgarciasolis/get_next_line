/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgarc4 <davgarc4@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 13:26:03 by davgarc4          #+#    #+#             */
/*   Updated: 2026/02/07 18:40:04 by davgarc4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char *get_next_line(int fd)
{
	static char	*buffer;
	char		*ptr;
	char		*result;

	if (!buffer)
		buffer = malloc(sizeof(char) * BUFFER_SIZE);
	read(fd, buffer, BUFFER_SIZE);
	ptr = ft_strchr(buffer, '\n');
	if (*ptr == '\n')
	{
		*ptr = '\0';
		result = ft_strdup(buffer);
	}
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

	ptr = get_next_line(fd);
	printf("%s", ptr);
	free(ptr);

	close(fd);
	return (0);
}
