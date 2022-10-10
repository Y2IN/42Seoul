/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_d_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:02:54 by yje               #+#    #+#             */
/*   Updated: 2022/10/10 17:50:21 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

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
		if (map->map_line[i + 1] == 'T')
			exit_game(map);
		if (map->map_line[i + 1] == 'E' && map->all_items == map->c_items)
			exit_game(map);
		else if (map -> map_line[i + 1] != '1' || map -> map_line[i + 1] != 'E')
		{
			map->map_line[i + 1] = 'P';
			map->map_line[i] = '0';
		}
	}
	setting_img_d1(map);
	map->walk_cnt++;
}


void	setting_img_d2(t_map *map, int hei, int wid)
{
	int	h64;
	int	w64;

	h64 = hei * 64;
	w64 = wid * 64;
	if (map->map_line[hei * map->width + wid] == '1')
		put_img(map, map->obj->tree[0].pt, w64, h64);
	else if (map->map_line[hei * map->width + wid] == 'C')
		put_img(map, map->obj->item[0].pt, w64, h64);
	else if(map->map_line[hei * map->width + wid] == 'T')
		put_img(map, map->obj->teacher[0].pt, w64 + 16, h64 + 16);
	else if (map->map_line[hei * map->width + wid] == 'E')
	{
		if (map->c_items == map->all_items)
			put_img(map, map->obj->door[1].pt, w64 + 16, h64 + 16);
		else
			put_img(map, map->obj->door[0].pt, w64 + 16, h64 + 16);
	}
}

void	put_img_rd_d(t_map *map, int w64, int h64)
{
	int rd;

	rd = map->x % 3;
	put_img(map, map->obj->sd[rd].pt, w64, h64);
	
}

void	setting_img_d3(t_map *map)
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
				put_img_rd_d(map, w64, h64);
			}
			wid++;
		}
		hei++;
	}
}

void	setting_img_d1(t_map *map)
{
	int 	hei;
	int 	wid;
	char	*walk_cnt;

	hei = 0;
	walk_cnt = ft_itoa(map->walk_cnt);
	while(hei < map->height)
	{
		wid = 0;
		while (wid < map->width)
		{
			put_img(map, map->obj->land[0].pt, wid * 64, hei * 64);
			setting_img_d2(map, hei, wid);
			wid++;
		}
		hei++;
	}
	setting_img_d3(map);
	mlx_string_put(map->mlx, map->win, 10, 10, create_trgb(0, 255, 255, 255), walk_cnt);
	free(walk_cnt);
}
