# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdurmaz <gdurmaz@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/28 23:59:44 by gdurmaz           #+#    #+#              #
#    Updated: 2024/01/04 17:13:19 by gdurmaz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OS = $(shell uname)

CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf

MLX_FLAGS = -L ./mlx_linux -lmlx -Ilmlx -lXext -lX11 -lm
MLX = mlx_linux
LIBFT = ./libft/libft.a
NAME = so_long
INCLUDES = -I./include -I./libft

BRIGHT_BLUE   = \033[34;1m
BRIGHT_GREEN   = \033[32;1m
RESET	= \033[0m

ifeq ($(OS), Darwin)
	MLX = mlx_macos
	MLX_FLAGS = -L $(MLX) -lmlx -framework OpenGL -framework AppKit -lm
endif

SRC = 	./src/Map/init_map.c \
		./src/Map/map_check.c \
		./src/Map/map_check_walls.c \
		./src/Map/map_values.c \
		./src/Map/path_validation.c \
		./src/Game/load_game.c \
		./src/Game/start_game.c \
		./src/Utils/error.c \
		./src/Utils/init_struct.c \
		./src/Utils/destroy.c

SRC-OBJ = $(SRC:.c=.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C ./libft

$(NAME): $(SRC-OBJ) $(LIBFT) $(GNL)
	$(MAKE) -C $(MLX)
	$(CC) $(CFLAGS) main.c $(SRC-OBJ) $(LIBFT) $(MLX_FLAGS) -o $(NAME) $(INCLUDES)
	@echo "$(BRIGHT_GREEN) Compiled with $(CFLAGS)$(RESET)"
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	$(MAKE) clean -C ./libft
	$(MAKE) clean -C $(MLX)
	$(RM) $(SRC-OBJ)
	@echo "$(BRIGHT_GREEN) Cleaned $(RESET)"

fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)
	@echo "$(BRIGHT_GREEN) Full cleaned $(RESET)"
leaks:
	valgrind --leak-check=full ./$(NAME) $(ARGS)

re: fclean all
