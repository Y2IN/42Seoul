/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 16:10:50 by yje               #+#    #+#             */
/*   Updated: 2022/09/30 16:25:18 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
    if (map->map_line[i] == 'C')
        map->c_item++;
    if (map->map_line[i] == 'E' && map->all_items == map->c_item)
        game_exit(map);
}