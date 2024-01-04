/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdurmaz <gdurmaz@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 10:25:07 by maricard          #+#    #+#             */
/*   Updated: 2024/01/04 13:11:15 by gdurmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_window(t_game *game)
{
	game->mlx.ptr = mlx_init();
	game->mlx.window = mlx_new_window(game->mlx.ptr, \
		game->map.width * SIZE, game->map.height * SIZE, "so long");
}

void	init_sprites(t_game *game)
{
	int	x;
	int	y;

	game->sprites.floor = mlx_xpm_file_to_image(game->mlx.ptr, \
		"./images/floor.xpm", &x, &y);
	game->sprites.wall = mlx_xpm_file_to_image(game->mlx.ptr, \
		"./images/wall.xpm", &x, &y);
	game->sprites.player = mlx_xpm_file_to_image(game->mlx.ptr, \
		"./images/player.xpm", &x, &y);
	game->sprites.collectible = mlx_xpm_file_to_image(game->mlx.ptr, \
		"./images/collectible.xpm", &x, &y);
	game->sprites.enemy = mlx_xpm_file_to_image(game->mlx.ptr, \
		"./images/enemy.xpm", &x, &y);
	game->sprites.exit_closed = mlx_xpm_file_to_image(game->mlx.ptr, \
		"./images/exit_closed.xpm", &x, &y);
	game->sprites.exit_open = mlx_xpm_file_to_image(game->mlx.ptr, \
		"./images/exit_open.xpm", &x, &y);
}
