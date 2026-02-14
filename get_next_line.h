/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgarc4 <davgarc4@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 13:26:29 by davgarc4          #+#    #+#             */
/*   Updated: 2026/02/14 13:04:00 by davgarc4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# ifndef SEPARATOR
#  define SEPARATOR '\n'
# endif


int		ft_strlen(char *str);
char	*ft_strchr(char *str, int c);
char	*ft_strdup(char *s, char c);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);

#endif