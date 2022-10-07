/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_a_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 17:51:41 by yje               #+#    #+#             */
/*   Updated: 2022/10/07 19:15:01 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	setting_img_a2(t_map *map, int hei, int wid)
{
	int	h64;
	int	w64;

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

void	setting_img_a3(t_map *map)
{
	int hei;
	int wid;
	int h64;
	int w64;

	hei = 0;
	while(hei < map->height)
	{
		wid = 0;
		while(wid < map->width)
		{
			if (map->map_line[hei * map->width +wid] == 'P')
			{
				h64 = hei * 64 + map->y;
				w64 = wid * 64 + map->x;
				put_img(map, map->obj->s1, w64, h64);
			}
			wid++;
		}
		hei++;
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
			put_img(map, map->obj->ld, wid * 64, hei * 64);
			setting_img_a2(map, hei, wid);
			wid++;
		}
		hei++;
	}
	setting_img_a3(map);
}

