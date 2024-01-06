/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdurmaz <gdurmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:55:23 by maricard          #+#    #+#             */
/*   Updated: 2024/01/05 02:10:39 by gdurmaz          ###   ########.fr       */
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
	put_string(game);
}

int	ft_loop_function(t_game *game)
{
	static int	x = 1;

	while (++x < 500)
		return (0);
	mlx_put_image_to_window(game->mlx.ptr, 
		game->mlx.window, game->sprites.bomb, 0, game->map.time++);
	if (game->map.time >= game->map.height * SIZE)
	{ 
		ft_printf("steps: %d\n", game->map.steps);
		ft_printf("---------\n Time is up! YOU LOST\n");
		destroy(game);
	}
	x = 0;
	return (1);
	// sleep(5);
	// mlx_put_image_to_window(game->mlx.ptr, 
	// 	game->mlx.window, game->sprites.enemy, SIZE, SIZE);
	// return (1);
}

int	gamex(t_game *game)
{
	draw_map(game);
	mlx_hook(game->mlx.window, 2, (1L << 0), key_pressed, game);
	// game->mlx.loop_param = 123;
	
	// mlx_loop_hook(game->mlx.ptr, sample_function, (void *)123);
	mlx_loop_hook(game->mlx.ptr, ft_loop_function, game);
    // my_game yapısının loop_hook ve loop_param değerlerini kullanarak sample_function'ı çağır
    // int result = game->mlx.loop_hook(game->mlx.loop_param);
	mlx_hook(game->mlx.window, 17, (1L << 2), close_game, game);
	mlx_loop(game->mlx.ptr);
	return (0);
}

