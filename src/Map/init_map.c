/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdurmaz <gdurmaz@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 00:04:57 by gdurmaz           #+#    #+#             */
/*   Updated: 2024/01/04 13:10:30 by gdurmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_file_extension(char *file_name_str)
{
	size_t	len;

	len = ft_strlen(file_name_str);
	if (len < 4 || ft_strncmp(file_name_str + len - 4, ".ber", 4))
		write_error("Map can only be a .ber file");
}

char	*read_map(char *map)
{
	char	*line;
	char	*map_str;
	char	*tmp;
	int		fd;

	fd = open(map, O_RDONLY);
	map_str = ft_calloc(1, 1);
	if (!map_str)
		return (NULL);
	while (1)
	{
		line = get_next_line(fd);
		if (line)
		{
			tmp = ft_strjoin(map_str, line);
			free(map_str);
			map_str = tmp;
			free (line);
		}
		else
			break ;
	}
	close (fd);
	return (map_str);
}

void	map_check(char *map_str)
{
	empty_map(map_str);
	empty_lines(map_str);
	wrong_content(map_str);
	wrong_shape(map_str);
	wrong_wall(map_str);
}

t_game	*init_map(char *map)
{
	char	*map_str;
	char	**map_arr;
	t_game	*game;

	map_str = read_map(map);
	map_check(map_str);
	map_arr = ft_split(map_str, '\n');
	game = map_values(map_arr);
	flood_fill(game);
	free(map_str);
	return (game);
}
