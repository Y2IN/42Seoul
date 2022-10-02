/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 16:10:50 by yje               #+#    #+#             */
/*   Updated: 2022/10/03 01:08:39 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void move_d(t_map *map)
{
    size_t i;

    i = 0;
    while(i < ft_strlen(map->map_line))
    {
        if (map -> map_line[i] == 'P')
            break ;
        i++;
    }
    if (map->map_line[i + 1] == '1')
        return ;
    if (map->map_line[i + 1] == 'C')
        map->c_items++;
    if (map->map_line[i + 1] == 'E' && map->all_items == map->c_items)
        exit_game(map);
    else if (map -> map_line[i + 1] != '1' || map -> map_line[i + 1] != 'E')
    {
        map -> map_line[i + 1] = 'P';
        map -> map_line[i] = '0';
    }
    
}

void move_a(t_map *map)
{
    size_t i;

    i = 0;
    while(i < ft_strlen(map->map_line))
    {
        if (map -> map_line[i] == 'P')
            break ;
        i++;
    }
    if (map->map_line[i - 1] == '1')
        return ;
    if (map->map_line[i - 1] == 'C')
        map->c_items++;
    if (map->map_line[i - 1] == 'E' && map->all_items == map->c_items)
        exit_game(map);
    else if (map -> map_line[i - 1] != '1' || map -> map_line[i + 1] != 'E')
    {
        map -> map_line[i - 1] = 'P';
        map -> map_line[i] = '0';
    }
    
}

void move_w(t_map *map)
{
    size_t i;

    i = 0;
    while(i < ft_strlen(map->map_line))
    {
        if (map -> map_line[i] == 'P')
            break ;
        i++;
    }
    if (map->map_line[i - map->width] == '1')
        return ;
    if (map->map_line[i - map->width] == 'C')
        map->c_items++;
    if (map->map_line[i - map->width] == 'E' && map->all_items == map->c_items)
        exit_game(map);
    else if (map -> map_line[i - map->width] != '1' || map -> map_line[i + 1] != 'E')
    {
        map -> map_line[i - map->width] = 'P';
        map -> map_line[i] = '0';
    }
    
}

void move_s(t_map *map)
{
    size_t i;

    i = 0;
    while(i < ft_strlen(map->map_line))
    {
        if (map -> map_line[i] == 'P')
            break ;
        i++;
    }
    if (map->map_line[i + map->width] == '1')
        return ;
    if (map->map_line[i + map->width] == 'C')
        map->c_items++;
    if (map->map_line[i + map->width] == 'E' && map->all_items == map->c_items)
        exit_game(map);
    else if (map -> map_line[i + map->width] != '1' || map -> map_line[i + 1] != 'E')
    {
        map -> map_line[i + map->width] = 'P';
        map -> map_line[i] = '0';
    }
    
}