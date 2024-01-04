/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdurmaz <gdurmaz@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 08:45:34 by maricard          #+#    #+#             */
/*   Updated: 2024/01/04 17:07:54 by gdurmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	count_rows(char **map_arr)
{
	size_t	i;

	i = 0;
	while (map_arr[i])
		i++;
	return (i);
}

char	**map_array(char *map_str, int width)
{
	char	**map;
	int		i;

	i = 0;
	map = ft_calloc(width + 1, sizeof(char *));
	if (!map)
	{
		free(map);
		return (0);
	}
	while (1)
	{
		map[i] = ft_strtrim(map_str, "\n");
		i++;
	}
}

size_t	count_collectibles(t_game *game)
{
	size_t	collectibles;
	size_t	x;
	size_t	y;

	collectibles = 0;
	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (game->map.map_array[y][x] == COLLECTIBLE)
				collectibles++;
			x++;
		}
		y++;
	}
	return (collectibles);
}

size_t	get_position(t_game *game, char axis, char obj)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (game->map.map_array[y][x] == obj)
			{
				if (axis == 'x')
					return (x);
				else
					return (y);
			}
			x++;
		}
		y++;
	}
	return (0);
}

t_game	*map_values(char **map_arr)
{
	t_game	*game;

	game = (t_game *)ft_calloc(1, sizeof(t_game));
	if (!game)
		write_error("Memory allocation error!");
	game->map.width = ft_strlen(map_arr[0]);
	game->map.height = count_rows(map_arr);
	game->map.map_array = map_arr;
	game->map.steps = 0;
	game->map.collectibles = count_collectibles(game);
	game->map.player_x = get_position(game, 'x', 'P');
	game->map.player_y = get_position(game, 'y', 'P');
	game->map.exit_x = get_position(game, 'x', 'E');
	game->map.exit_y = get_position(game, 'y', 'E');
	game->map.collected = 0;
	return (game);
}
