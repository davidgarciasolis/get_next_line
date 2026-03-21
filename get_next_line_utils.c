/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgarc4 <davgarc4@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 13:26:15 by davgarc4          #+#    #+#             */
/*   Updated: 2026/03/21 19:29:32 by davgarc4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return ((char *)&str[i]);
		i++;
	}
	if (str[i] == c)
		return ((char *)&str[i]);
	return (NULL);
}

char	*ft_strdup(char *s, char c)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = malloc(ft_strlen(s) + 2);
	if (!ptr)
		return (NULL);
	while (s[i])
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = c;
	i++;
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	size;
	char	*ptr;
	size_t	x;
	size_t	y;

	if (!s1)
		return (ft_strdup(s2, '\n'));
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	x = 0;
	y = 0;
	while (s1[x])
	{
		ptr[x] = s1[x];
		x++;
	}
	while (s2[y])
	{
		ptr[x + y] = s2[y];
		y++;
	}
	ptr[x + y] = '\0';
	return (ptr);
}

size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	const char	*s;
	char		*d;
	size_t		i;

	s = (char *)src;
	d = (char *)dst;
	i = 0;
	if (size != 0)
	{
		while (i < size - 1 && s[i])
		{
			d[i] = s[i];
			i++;
		}
		d[i] = '\0';
	}
	while (s[i])
	{
		i++;
	}
	return (i);
}
