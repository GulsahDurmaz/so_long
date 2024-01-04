/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdurmaz <gdurmaz@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:52:16 by gdurmaz           #+#    #+#             */
/*   Updated: 2024/01/04 16:46:41 by gdurmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_g_strchr(char *s, int c)
{
	if (!s)
		return (0);
	while (*s && *s != (char)c)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}

char	*ft_g_strjoin(char *line, char *buffer)
{
	size_t	i;
	size_t	j;
	char	*new;

	i = 0;
	j = 0;
	new = malloc(sizeof(char) * (ft_g_strlen(line) + ft_g_strlen(buffer)) + 1);
	if (!new)
		return (0);
	if (line)
	{
		while (line[i])
		{
			new[i] = line[i];
			i++;
		}
	}
	while (buffer[j])
	{
		new[i + j] = buffer[j];
		j++;
	}
	new[i + j] = '\0';
	return (new);
}

char	*ft_g_strdup(const char *src)
{
	char	*dest;
	size_t	len;

	len = ft_g_strlen(src) + 1;
	dest = (char *)malloc(len * sizeof(char));
	if (!dest)
	{
		return (0);
	}
	dest = ft_g_memcpy(dest, src, len);
	return (dest);
}

void	*ft_g_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if ((dst == src) || n == 0)
		return (dst);
	if (!dst && !src)
		return (0);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}

char	*ft_g_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_s;
	size_t	i;
	size_t	l_s;

	i = 0;
	l_s = ft_g_strlen(s);
	if (len == 0 || s[i] == '\0' || l_s < (size_t) start)
	{
		sub_s = malloc(1);
		if (!sub_s)
			return (0);
		sub_s[0] = '\0';
		return (sub_s);
	}
	if (len >= l_s || l_s < len + start)
		len = l_s - start;
	sub_s = (char *)malloc (sizeof(char) * (len + 1));
	if (!sub_s)
		return (0);
	while (i < len)
		sub_s[i++] = s[start++];
	sub_s[i] = '\0';
	return (sub_s);
}
