/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdurmaz <gdurmaz@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:38:55 by maricard          #+#    #+#             */
/*   Updated: 2024/01/04 17:06:28 by gdurmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int	ft_error(t_game *root, char *str)
// {
// 	ft_printf("Error\n");
// 	ft_printf("%s\n", str);
// 	destroy(root);
// 	exit(1);
// }

void	write_error(char *str)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(str, 2);
	exit (1);
}
