/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:37:05 by yje               #+#    #+#             */
/*   Updated: 2022/10/06 15:37:09 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	exit_game(t_map *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

void	print_error(char *msg)
{
	printf("ERROR : %s\n", msg);
	exit(1);
}
