/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdurmaz <gdurmaz@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:54:14 by gdurmaz           #+#    #+#             */
/*   Updated: 2024/01/04 16:47:57 by gdurmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>// read
# include <fcntl.h>// open
# include <stdio.h>// printf

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*ft_g_strjoin(char *line, char *buffer);
char	*ft_g_strchr(char *s, int c);
char	*ft_g_strdup(const char *src);
char	*ft_g_substr(char const *s, unsigned int start, size_t len);
size_t	ft_g_strlen(const char *str);
void	*ft_g_memcpy(void *dst, const void *src, size_t n);

#endif
