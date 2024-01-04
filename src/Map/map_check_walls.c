/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_walls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdurmaz <gdurmaz@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 13:30:03 by gdurmaz           #+#    #+#             */
/*   Updated: 2024/01/04 12:33:45 by gdurmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	wall_check_horizontal(char *map)
{
	size_t	i;
	size_t	width;
	size_t	map_len;

	i = 0;
	width = 0;
	map_len = ft_strlen(map);
	while (map[i] != '\0')
	{
		while (map[i] != '\n' && map[i] != '\0')
		{
			if (map[i] != '1')
				write_error("Wrong wall content!");
			i++;
			width++;
		}
		i = map_len - width;
		while (map[i] != '\0')
		{
			if (map[i] != '1')
				write_error("Wrong wall content!");
			i++;
		}
	}
}

void	wall_check_vertical(char *map)
{
	size_t	i;
	size_t	width;
	size_t	map_len;

	i = 0;
	width = 0;
	map_len = ft_strlen(map);
	while (map[i] != '\0')
	{
		while (map[i] != '\n')
		{
			i++;
			width++;
		}
		i++;
		while (i < map_len - width -1)
		{
			if (map[i] != '1' || map[i + width -1] != '1')
				write_error("Wrong wall content!");
			i = i + width + 1;
		}
		i = i + width;
	}
}
