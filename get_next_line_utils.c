/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgarc4 <davgarc4@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 13:26:15 by davgarc4          #+#    #+#             */
/*   Updated: 2026/03/23 19:40:26 by davgarc4         ###   ########.fr       */
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

char	*ft_substr(char *s, int start, size_t len)
{
	char	*ptr;
	size_t	size;
	size_t	idx;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	if (start < 0 || (size_t)start >= size)
		return (ft_strdup(""));
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

char	*ft_strdup(char *s)
{
	char		*copy;
	size_t		i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	copy = malloc(sizeof(char) * (i + 1));
	if (copy == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len;
	char	*ptr;
	size_t	i;
	size_t	j;

	if (!s1)
		return (ft_strdup(s2));
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
