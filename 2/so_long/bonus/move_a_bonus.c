/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_a_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 17:51:41 by yje               #+#    #+#             */
/*   Updated: 2022/10/06 21:45:32 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	setting_img_a2(t_map *map, int hei, int wid)
{
	int	h64;
	int	w64;

	h64 = hei * 64;
	w64 = wid * 64;
	while (++hei < map->height)
	{
		while (++wid < map->width)
		{
			h64 = hei * 64;
			w64 = wid * 64;
			if (map->map_line[hei * map->width + wid] == '1')
				put_img(map, map->obj->tr, w64, h64);
			else if (map->map_line[hei * map->width + wid] == 'C')
				put_img(map, map->obj->it, w64, h64);
			else if (map->map_line[hei * map->width + wid] == 'T')
				put_img(map, map->obj->t1, w64 + 16, h64 + 16);
			else if (map->map_line[hei * map->width + wid] == 'E')
			{
				if (map->c_items == map->all_items)
					put_img(map, map->obj->d1, w64 + 16, h64 + 16);
				else
					put_img(map, map->obj->d1, w64 + 16, h64 + 16);
			}
		}
	}	
}
void	setting_img_a(t_map *map)
{
	int hei;
	int wid;

	hei = 0;
	while(hei < map->height)
	{
		wid = 0;
		while(wid < map->width)
		{
			put_img(map, map->obj->ld, wid * 64, hei * 64);
			setting_img_a2(map, hei, wid);
			wid++;
		}
		hei++;
	}
	setting_img_a3(map, hei, wid);
}

void	setting_img_a3(t_map *map, int hei, int wid)
{
	int i;

	i = 0;
	while(i < map->map_line[i])
	{
		if (map->map_line[i] == 'P')
			put_img(map, map->obj->s1, wid + 8, hei + 8);
		i++;
	}
}

void	setting_img(t_map *map)
{
	int hei;
	int wid;

	hei = 0;
	while(hei < map->height)
	{
		wid = 0;
		while (wid < map->width)
		{
			if(map->map_line[hei * map->width + wid] == 'P')
				put_img(map, map->obj->s1, wid * 64, hei * 64);
			wid++;		
		}
		hei++;
	}
}


void	move_a(t_map *map)
{
	int	i;
	
	i = 0;
	map->c_items = 0;
	while(i < map->map_size)
	{
		if(map->map_line[i - 1] == 'C')
			map->c_items++;
	}
	if (map->map_line[i - 1] == '1')
		return ;
	if (map->map_line[i - 1] == 'E' && map->all_items == map->c_items)
		exit_game(map);
	else if (map -> map_line[i + 1] != '1' || map -> map_line[i + 1] != 'E')
	{
		map->map_line[i + 1] = 'P';
		map->map_line[i] = '0';
		map->walk_cnt++;
		setting_img(map);
	}
}		


