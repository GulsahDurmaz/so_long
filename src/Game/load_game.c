/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdurmaz <gdurmaz@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:55:23 by maricard          #+#    #+#             */
/*   Updated: 2024/01/04 18:19:26 by gdurmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image_to_window(t_game *game, int column, int line)
{
	if (game->map.map_array[game->map.curr_y][game->map.curr_x] == WALL)
		mlx_put_image_to_window(game->mlx.ptr, \
			game->mlx.window, game->sprites.wall, column, line);
	else if (game->map.map_array[game->map.curr_y][game->map.curr_x] == FLOOR)
		mlx_put_image_to_window(game->mlx.ptr, \
			game->mlx.window, game->sprites.floor, column, line);
	else if (game->map.map_array[game->map.curr_y][game->map.curr_x] == PLAYER)
		mlx_put_image_to_window(game->mlx.ptr, \
			game->mlx.window, game->sprites.player, column, line);
	else if (game->map.map_array[game->map.curr_y][game->map.curr_x] == 'C')
		mlx_put_image_to_window(game->mlx.ptr, \
			game->mlx.window, game->sprites.collectible, column, line);
	else if (game->map.map_array[game->map.curr_y][game->map.curr_x] == ENEMY)
		mlx_put_image_to_window(game->mlx.ptr, \
			game->mlx.window, game->sprites.enemy, column, line);
	else if (game->map.map_array[game->map.curr_y][game->map.curr_x] == EXIT)
		mlx_put_image_to_window(game->mlx.ptr, \
			game->mlx.window, game->sprites.exit_closed, column, line);
}

void	draw_map(t_game *game)
{
	int	column;
	int	line;

	line = 0;
	game->map.curr_y = 0;
	while (game->map.map_array[game->map.curr_y])
	{
		column = 0;
		game->map.curr_x = 0;
		while (game->map.map_array[game->map.curr_y][game->map.curr_x])
		{
			put_image_to_window(game, column, line);
			game->map.curr_x++;
			column += SIZE;
		}
		game->map.curr_y++;
		line += SIZE;
	}
	game->map.curr_x = game->map.player_x;
	game->map.curr_y = game->map.player_y;
	mlx_string_put(game->mlx.ptr, game->mlx.window, \
			SIZE, SIZE / 2, 0xcddc39, "Collected: 0");
}

int	gamex(t_game *game)
{
	draw_map(game);
	mlx_hook(game->mlx.window, 2, (1L << 0), key_pressed, game);
	mlx_hook(game->mlx.window, 17, (1L << 2), close_game, game);
	mlx_loop(game->mlx.ptr);
	return (0);
}
