/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 20:52:32 by yje               #+#    #+#             */
/*   Updated: 2022/10/12 19:08:16 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	enemy_move_0(t_map *map, int i)
{
	if (map->map_line[i - map->width] == '0')
	{
		map->map_line[i] = '0';
		map->map_line[i - map->width] = 'T';
	}
}

void	enemy_move_1(t_map *map, int i)
{
	if (map->map_line[i + 1] == '0')
	{
		map->map_line[i] = '0';
		map->map_line[i + 1] = 'T';
	}
}

void	enemy_move_2(t_map *map, int i)
{
	if (map->map_line[i + map->width] == '0')
	{
		map->map_line[i] = '0';
		map->map_line[i + map->width] = 'T';
	}
}

void	enemy_move_3(t_map *map, int i)
{
	if (map->map_line[i - 1] == '0')
	{
		map->map_line[i] = '0';
		map->map_line[i - 1] = 'T';
	}
}
