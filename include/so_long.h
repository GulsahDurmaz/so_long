/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdurmaz <gdurmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 09:44:39 by maricard          #+#    #+#             */
/*   Updated: 2024/01/05 02:00:32 by gdurmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// Libraries
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifdef __APPLE__
#  include "../mlx_macos/mlx.h"
# else
#  include "../mlx_linux/mlx.h"
#  include <X11/X.h>
# endif

// Libft library
# include "libft.h"
# include "get_next_line.h"

// Macros
# define SIZE 50

# define WALL '1'
# define FLOOR '0'
# define PLAYER 'P'
# define COLLECTIBLE 'C'
# define EXIT 'E'
# define ENEMY 'X'

# ifdef __APPLE__
#  define ESC 53
#  define UP 126
#  define DOWN 125
#  define LEFT 123
#  define RIGHT 124
#  define W 13
#  define A 0
#  define S 1
#  define D 2
# else
#  define ESC 65307
#  define UP 65362
#  define DOWN 65364
#  define LEFT 65361
#  define RIGHT 65363
#  define W 119
#  define S 115
#  define A 97
#  define D 100
# endif

// Structs
typedef struct s_map
{
	char	**map_array;
	size_t	width;
	size_t	height;
	size_t	collectibles;
	size_t	curr_x;
	size_t	curr_y;
	size_t	collected;
	size_t	player_x;
	size_t	player_y;
	size_t	exit_x;
	size_t	exit_y;
	size_t	steps;
	size_t	time;
}		t_map;

typedef struct s_sprites
{
	void	*floor;
	void	*wall;
	void	*player;
	void	*collectible;
	void	*exit_closed;
	void	*exit_open;
	void	*enemy;
	void	*bomb;
}		t_sprites;

typedef struct s_mlx
{
	void		*ptr;
	void		*window;
}		t_mlx;

typedef struct s_game
{
	t_map		map;
	t_mlx		mlx;
	t_sprites	sprites;
}		t_game;

// Map - map_check_wall
void	wall_check_horizontal(char *map);
void	wall_check_vertical(char *map);

// Map - map_check
void	empty_map(char *map);
void	empty_lines(char *map);
void	wrong_content(char *map);
void	wrong_shape(char *map);
void	wrong_wall(char *map);

// Map - init_map
void	check_file_extension(char *file_name_str);
char	*read_map(char *map);
void	map_check(char *map_str);
t_game	*init_map(char *map);

// Map - map_values
t_game	*map_values(char **map_arr);

// Map - Path_validation
int		path_validation(t_game *tmp, size_t y, size_t x);
void	flood_fill(t_game *game);

// Utils
// int		ft_error(t_game *game, char *str);
int		close_game(t_game *game);
void	destroy(t_game *game);
void	free_arrays(char **array);
void	init_window(t_game *game);
void	init_sprites(t_game *game);
void	write_error(char *str);

// Game start_game
int		check_next_tile(t_game *game, int x, int y);
int		gamex(t_game *game);
int		key_pressed(int key, t_game *game);
void	put_string(t_game *game);

#endif
