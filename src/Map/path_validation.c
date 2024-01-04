/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdurmaz <gdurmaz@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 10:16:15 by maricard          #+#    #+#             */
/*   Updated: 2024/01/04 13:10:51 by gdurmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	path_validation(t_game *tmp, size_t y, size_t x)
{
	if (tmp->map.map_array[y][x] == '1')
		return (0);
	if (tmp->map.map_array[y][x] == 'C')
		tmp->map.collectibles--;
	if (tmp->map.map_array[y][x] == 'E')
	{
		tmp->map.exit_x = 1;
		return (0);
	}
	tmp->map.map_array[y][x] = '1';
	if (path_validation(tmp, y + 1, x))
		return (1);
	if (path_validation(tmp, y - 1, x))
		return (1);
	if (path_validation(tmp, y, x + 1))
		return (1);
	if (path_validation(tmp, y, x - 1))
		return (1);
	return (0);
}

void	free_map_array(char **array, size_t grid_height)
{
	size_t	i;

	i = 0;
	while (i < grid_height)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	flood_fill(t_game *game)
{
	t_game	tmp;
	size_t	i;

	tmp.map.height = game->map.height;
	tmp.map.width = game->map.width;
	tmp.map.collectibles = game->map.collectibles;
	tmp.map.player_x = game->map.player_x;
	tmp.map.player_y = game->map.player_y;
	tmp.map.exit_x = 0;
	tmp.map.map_array = (char **)malloc(tmp.map.height * sizeof(char *));
	i = 0;
	if (!tmp.map.map_array)
		write_error("Memory allocation problem");
	while (i < tmp.map.height)
	{
		tmp.map.map_array[i] = ft_strdup(game->map.map_array[i]);
		i++;
	}
	path_validation(&tmp, tmp.map.player_y, tmp.map.player_x);
	if (!(tmp.map.exit_x == 1 && tmp.map.collectibles == 0))
		write_error("Path error!");
	free_map_array(tmp.map.map_array, tmp.map.height);
}
