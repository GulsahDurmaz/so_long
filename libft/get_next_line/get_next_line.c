/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdurmaz <gdurmaz@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:02:41 by gdurmaz           #+#    #+#             */
/*   Updated: 2024/01/04 16:47:22 by gdurmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_g_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i])
		i++;
	return (i);
}

char	*ft_get_line(char *stash)
{
	char	*printed_line;
	ssize_t	i;

	i = 0;
	if (stash[i] == '\0')
		return (0);
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	printed_line = ft_g_substr(stash, 0, i + 1);
	if (printed_line == 0)
	{
		free(printed_line);
		printed_line = NULL;
	}
	return (printed_line);
}

char	*ft_clean_remaining(char *stash)
{
	char	*remaining_text;
	ssize_t	i;

	i = 0;
	if (stash[i] == '\0')
		return (0);
	while (stash[i] != '\0' && stash[i] != '\n')
		i++;
	remaining_text = ft_g_substr(stash, i + 1, ft_g_strlen(stash) - i);
	if (*remaining_text == 0)
	{
		free(remaining_text);
		remaining_text = NULL;
	}
	free(stash);
	stash = NULL;
	return (remaining_text);
}

char	*ft_read_file(int fd, char *stash, char *buffer)
{
	ssize_t	bytes_read;
	char	*tmp;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free (stash);
			return (NULL);
		}
		else if (bytes_read == 0)
			break ;
		buffer[bytes_read] = 0;
		if (!stash)
			stash = ft_g_strdup("");
		tmp = stash;
		stash = ft_g_strjoin(tmp, buffer);
		free (tmp);
		tmp = NULL;
		if (ft_g_strchr(buffer, '\n'))
			break ;
	}
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*printed_line;
	char		*buffer;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free (stash);
		stash = NULL;
		free (buffer);
		buffer = NULL;
		return (NULL);
	}
	stash = ft_read_file(fd, stash, buffer);
	free(buffer);
	buffer = NULL;
	if (!stash)
		return (NULL);
	printed_line = ft_get_line(stash);
	stash = ft_clean_remaining(stash);
	return (printed_line);
}
