/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgarc4 <davgarc4@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 13:26:15 by davgarc4          #+#    #+#             */
/*   Updated: 2026/03/21 22:52:49 by davgarc4         ###   ########.fr       */
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

char	*handle_read_result(int bytes, char *saved, char *buffer)
{
	if (bytes < 0)
	{
		free(buffer);
		free(saved);
		return (NULL);
	}
	free(buffer);
	return (saved);
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
	size_t	len;
	char	*ptr;
	size_t	i;
	size_t	j;

	if (!s1)
		return (ft_strdup(s2, '\n'));
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	ptr = malloc(len);
	if (!ptr)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		ptr[i + j] = s2[j];
		j++;
	}
	ptr[i + j] = '\0';
	return (ptr);
}
