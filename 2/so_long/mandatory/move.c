/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 16:10:50 by yje               #+#    #+#             */
/*   Updated: 2022/10/02 22:16:45 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void move_d(t_map *map)
{
    int i;

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
        map->c_item++;
    if (map->map_line[i + 1] == 'E' && map->all_items == map->c_item)
        exit;
    else if (map -> map_line[i + 1] == 0 || map -> map_line[i + 1] != 'E')
        map -> map_line[i + 1] = 'P';
        map -> map_line[i] = '0';
}