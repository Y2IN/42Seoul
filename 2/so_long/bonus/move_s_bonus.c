/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_s_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:01:43 by yje               #+#    #+#             */
/*   Updated: 2022/10/11 19:45:06 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	setting_img_s2(t_map *map, int hei, int wid)
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

void	put_img_rd_s(t_map *map, int w64, int h64)
{
	int rd;

	rd = map->y % 3;
	put_img(map, map->obj->ss[rd].pt, w64, h64);
	
}

void	setting_img_s3(t_map *map)
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
				put_img_rd_s(map, w64, h64);
			}
			wid++;
		}
		hei++;
	}
}

void	setting_img_s1(t_map *map)
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
			setting_img_s2(map, hei, wid);
			wid++;
		}
		hei++;
	}
	setting_img_s3(map);
	mlx_string_put(map->mlx, map->win, 10, 10, create_trgb(0, 255, 255, 255), walk_cnt);
	free(walk_cnt);
}

static int	move_s2(t_map *map)
{
	int	i;

	i = 0;
	while (i++ < map->map_size)
		if (map->map_line[i] == 'P')
			break ;
	if (map->y == 32)
		if (map->map_line[i + map->width] == '1')
			return (1);
	if (map->y == 48)
		if (map->map_line[i + map->width] == 'E' && map->c_items != map->all_items)
			return (1);
	if (map->y == 64)
	{
		if (map->map_line[i + map->width] == 'T')
			exit_game(map);
		if (map->map_line[i + map->width] == 'E' && map->c_items == map->all_items)
			exit_game(map);
		map->map_line[i + map->width] = 'P';
		map->map_line[i] = '0';
		map->y = 0;
	}
	return (0);
}

void	move_s(t_map *map)
{
	int	i;

	i = 0;
	while (i++ < map->map_size)
		if (map->map_line[i] == 'C')
			map->c_items++;
	if (move_s2(map))
		return ;
	map->walk_cnt++;
	move_enemy(map);
	setting_img_s1(map);
}
