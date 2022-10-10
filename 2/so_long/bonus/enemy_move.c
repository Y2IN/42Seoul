/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:55:53 by yje               #+#    #+#             */
/*   Updated: 2022/10/10 21:10:39 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	make_enemy(t_map *map)
{
	int	num;

	while (map->map_line)
	{
		num = rand() % ((int)ft_strlen(map->map_line));
		if (map->map_line[num] == '0')
		{
			map->map_line[num] = 'T';
			return ;
		}
	}
}

void	move_enemy(t_map *map)
{
	int	num;
	int	i;

	i = 0;
	while (1)
	{
		if (map->map_line[i] == 'T')
			break ;
		i++;
	}
	if (map->walk_cnt % 8 == 0 && map->walk_cnt != 0)
	{
		num = rand() % 4;
		if (num == 0)
			enemy_move_0(map, i);
		else if (num == 1)
			enemy_move_1(map, i);
		else if (num == 2)
			enemy_move_2(map, i);
		else
			enemy_move_3(map, i);
	}
}
