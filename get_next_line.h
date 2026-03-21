/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgarc4 <davgarc4@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 13:26:29 by davgarc4          #+#    #+#             */
/*   Updated: 2026/03/21 22:52:49 by davgarc4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef SEPARATOR
#  define SEPARATOR '\n'
# endif

int		ft_strlen(char *str);
char	*ft_strchr(char *str, int c);
char	*ft_strdup(char *s, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*free_and_null(char *ptr);
char	*ft_substr(char *s, int start, size_t len);
char	*handle_read_result(int bytes, char *saved, char *buffer);
char	*get_next_line(int fd);

#endif