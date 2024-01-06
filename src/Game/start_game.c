/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdurmaz <gdurmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 11:48:59 by maricard          #+#    #+#             */
/*   Updated: 2024/01/05 00:03:15 by gdurmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// char	*put_string(t_game *game)
// {
// 	char	*str;
// 	char	*tmp;

// 	tmp = ft_itoa(game->map.collected);
// 	str = ft_strjoin("Collected: ", tmp);
// 	return (str);
// }

void	put_string(t_game *game)
{
	char	*collected;

	collected = ft_itoa(game->map.collected);
	mlx_string_put(game->mlx.ptr, game->mlx.window, SIZE, 15, 0xcddc39, "Collected: ");
	mlx_string_put(game->mlx.ptr, game->mlx.window, SIZE * 3, 15, 0xcddc39, collected);
	free(collected);
	return ;
}

void	move_player(t_game *game, int x, int y)
{
	if (game->map.map_array[y][x] == COLLECTIBLE)
	{
		game->map.map_array[y][x] = '0';
		game->map.collected++;
		put_string(game);
		
	}
	if (game->map.collected == game->map.collectibles)
	{
		mlx_put_image_to_window(game->mlx.ptr, \
			game->mlx.window, game->sprites.exit_open, \
				game->map.exit_x * SIZE, game->map.exit_y * SIZE);
	}
	if (game->map.map_array[game->map.curr_y][game->map.curr_x] == EXIT)
	{
		mlx_put_image_to_window(game->mlx.ptr, \
			game->mlx.window, game->sprites.player, x * SIZE, y * SIZE);
		mlx_put_image_to_window(game->mlx.ptr, \
			game->mlx.window, game->sprites.exit_closed, \
				game->map.curr_x * SIZE, game->map.curr_y * SIZE);
		game->map.steps++;
		return ;
	}
	mlx_put_image_to_window(game->mlx.ptr, \
		game->mlx.window, game->sprites.player, x * SIZE, y * SIZE);
	mlx_put_image_to_window(game->mlx.ptr, \
		game->mlx.window, game->sprites.floor, \
			game->map.curr_x * SIZE, game->map.curr_y * SIZE);
	game->map.steps++;
}

int	check_next_tile(t_game *game, int x, int y)
{
	if (game->map.map_array[y][x] == WALL)
		return (0);
	if (game->map.map_array[y][x] == ENEMY)
	{
		move_player(game, x, y);
		ft_printf("steps: %d\n", game->map.steps);
		ft_printf("---------\n Tofu got caught by Gulsah! YOU LOST\n");
		destroy(game);
	}
	else if (game->map.map_array[y][x] == EXIT)
	{
		if (game->map.collected == game->map.collectibles)
		{
			move_player(game, x, y);
			ft_printf("steps: %d\n", game->map.steps);
			ft_printf("---------\n YOU WON\n");
			destroy(game);
		}
		return (0);
	}
	move_player(game, x, y);
	ft_printf("steps: %d\n", game->map.steps);
	game->map.curr_x = x;
	game->map.curr_y = y;
	return (0);
}

int	key_pressed(int key, t_game *game)
{
	if (key == UP || key == W)
		check_next_tile(game, game->map.curr_x, game->map.curr_y - 1);
	else if (key == DOWN || key == S)
		check_next_tile(game, game->map.curr_x, game->map.curr_y + 1);
	else if (key == LEFT || key == A)
		check_next_tile(game, game->map.curr_x - 1, game->map.curr_y);
	else if (key == RIGHT || key == D)
		check_next_tile(game, game->map.curr_x + 1, game->map.curr_y);
	else if (key == ESC)
	{
		ft_printf("---------\nGAME OVER\n");
		destroy(game);
	}
	return (0);
}
