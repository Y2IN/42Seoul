/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 16:10:50 by yje               #+#    #+#             */
/*   Updated: 2022/10/07 20:05:03 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_d(t_map *map)
{
	size_t	i;

	i = 0;
	map->x = map->x + 8;
	if (map->x >= 64)
		map->x = 64;
	while (i < ft_strlen(map->map_line))
	{
		if (map -> map_line[i] == 'P')
			break ;
		i++;
	}
	if (map->x >= 64)
	{	
		if (map->map_line[i + 1] == '1')
			return ;
		if (map->map_line[i + 1] == 'E' && map->all_items != map->c_items)
			return ;
		map->x = 0;
		if (map->map_line[i + 1] == 'C')
			map->c_items++;
		if (map->map_line[i + 1] == 'E' && map->all_items == map->c_items)
			exit_game(map);
		else if (map -> map_line[i + 1] != '1' || map -> map_line[i + 1] != 'E')
		{
			map->map_line[i + 1] = 'P';
			map->map_line[i] = '0';
			map->walk_cnt++;
		}
	}
	setting_img(map);
}

void	move_a(t_map *map)
{
	size_t	i;

	i = 0;
	map->x = map->x - 8;
	if (map->x <= 0)
		map->x = 0;
	while (i < ft_strlen(map->map_line))
	{
		if (map -> map_line[i] == 'P')
			break ;
		i++;
	}
	if (map->x <= 0)
	{	
		if (map->map_line[i - 1] == '1')
			return ;
		if (map->map_line[i - 1] == 'E' && map->all_items != map->c_items)
			return ;
		map->x = 64;
		if (map->map_line[i - 1] == 'C')
			map->c_items++;
		if (map->map_line[i - 1] == 'E' && map->all_items == map->c_items)
			exit_game(map);
		else if (map -> map_line[i - 1] != '1' || map -> map_line[i - 1] != 'E')
		{
			map->map_line[i - 1] = 'P';
			map->map_line[i] = '0';
			map->walk_cnt++;
		}
	}
	setting_img(map);
}		

void	move_w(t_map *map)
{
	size_t	i;

	i = 0;
	map->y = map->y - 8;
	if (map->y <= 0)
		map->y = 0;
	while (i < ft_strlen(map->map_line))
	{
		if (map -> map_line[i] == 'P')
			break ;
		i++;
	}
	if (map->y <= 0)
	{	
		if (map->map_line[i - map->width] == '1')
			return ;
		if (map->map_line[i - map->width] == 'E' && map->all_items != map->c_items)
			return ;
		map->y = 64;
		if (map->map_line[i - map->width] == 'C')
			map->c_items++;
		if (map->map_line[i - map->width] == 'E' && map->all_items == map->c_items)
			exit_game(map);
		else if (map -> map_line[i - map->width] != '1' || map -> map_line[i - map->width] != 'E')
		{
			map->map_line[i - map->width] = 'P';
			map->map_line[i] = '0';
			map->walk_cnt++;
		}
	}
	setting_img(map);
}

void	move_s(t_map *map)
{
	size_t	i;

	i = 0;
	map->y = map->y + 8;
	if (map->y >= 64)
		map->y = 64;
	while (i < ft_strlen(map->map_line))
	{
		if (map -> map_line[i] == 'P')
			break ;
		i++;
	}
	if (map->y >= 64)
	{	
		if (map->map_line[i + map->width] == '1')
			return ;
		if (map->map_line[i + map->width] == 'E' && map->all_items != map->c_items)
			return ;
		map->y = 0;
		if (map->map_line[i + map->width] == 'C')
			map->c_items++;
		if (map->map_line[i + map->width] == 'E' && map->all_items == map->c_items)
			exit_game(map);
		else if (map -> map_line[i + map->width] != '1' || map -> map_line[i + map->width] != 'E')
		{
			map->map_line[i + map->width] = 'P';
			map->map_line[i] = '0';
			map->walk_cnt++;
		}
	}
	setting_img(map);
}