/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdurmaz <gdurmaz@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 23:55:08 by gdurmaz           #+#    #+#             */
/*   Updated: 2024/01/04 12:45:41 by gdurmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2)
	{
		ft_printf("Program needs <so_long> & <map.ber> to start!");
		return (0);
	}
	check_file_extension(av[1]);
	game = init_map(av[1]);
	init_window(game);
	if (!game->mlx.ptr)
		return (EXIT_FAILURE);
	init_sprites(game);
	gamex(game);
}

