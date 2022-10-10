/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:55:53 by yje               #+#    #+#             */
/*   Updated: 2022/10/10 18:20:04 by yje              ###   ########.fr       */
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

void move_enemy(t_map *map)
{
	int num;
	int i;

	i = 0;
	while(1)
	{
		if (map->map_line[i] == 'T')
			break ;
		i++;
	}
	if (map->walk_cnt % 8 == 0 && map->walk_cnt != 0)
	{
		num = rand() % 4;
		if (num == 0)
		{
			if (map->map_line[i - map->width] == '0')
			{
				map->map_line[i] = '0';
				map->map_line[i - map->width] = 'T';
			}
		}
		else if (num == 1)
		{
			if (map->map_line[i + 1] == '0')
			{	
				map->map_line[i] = '0';
				map->map_line[i + 1] = 'T';
			}
		}
		else if (num == 2)
		{
			if (map->map_line[i + map->width] == '0')
			{
				map->map_line[i] = '0';
				map->map_line[i + map->width] = 'T';
			}
		}
		else
		{
			if (map->map_line[i - 1] == '0')
			{	
				map->map_line[i] = '0';
				map->map_line[i - 1] = 'T';
			}
		}
	}
}
