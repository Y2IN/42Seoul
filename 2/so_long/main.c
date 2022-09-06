/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 17:12:49 by yje               #+#    #+#             */
/*   Updated: 2022/09/06 16:24:08 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int fd_check(t_map *map)
{
	int	fd;

	fd = open("./map.ber", O_RDONLY);
    if (fd < 0)
        error("failed open.\n");
	return (fd);
	
}
int map_size_check(int fd, t_map *map)
{
    int	size;
	char *line;

	size = 0;
	line = get_next_line(fd);
	while (line) 
	{
		free(line);
		line = get_next_line(fd);
		size++;
	} //마지막까지 가면 널 반환
	map -> height = size;
	return (size);
}

int	first_line_check(char *line, t_map *map)
{
	int	width;
	int size;

	size = ft_strlen(line);
	width = 0;
	while (width < size -1)
	{
		if (line[width] != '1')
			return (-1);
		width++;
	}
	// if (line[width] == '\n')
	// {
	// 	//개행일 때 세는 거 아닌감? ㅎㅎ
	// 	//width로 중간 줄이 몇 줄 나오는 지 알 수 있다???????????? 난 모르겠따
		
	// }
	return (0);
}

void	map_init(t_map *map)
{
    int 	fd;
    int     map_size;
	int		width;
	char 	*line;
    
    fd = fd_check(map);
	map_size = map_size_check(fd, map);
	close(fd);
	fd = fd_check(map);
	// line = get_next_line(fd);
	// width = first_line_check(line, map);
	// if (width == -1)
	// 	error("error.\n");
		
}

// void    map_init(t_map *map)
// {
//     // 1 step - open으로 map불러와서 map size 체크 -> read를 통해서 한번에 모든 맵을 읽은 다음, 개행의 갯수를 구하면 됨. 
//     // 다 구했으면 size는 map->height, 읽은것은 map->map_line에 저장, close(fd)필수
//     // 2 step - 다시 map open해서 gnl 사용해서 한 줄씩 읽어오기
//     // 2-1 - 첫 줄은 1(벽)로만 채워져있음 (+ 마지막 개행문자) 그거 판단하는거 하나 만들기
//     // 2-2 중간 줄은 다른 판단이 필요함, 아까 구한 width로 중간 줄이 몇 줄 나오는 지 알 수 있다. 해보도록. ㅎㅎㅎ
//     // 2-3 마지막 줄은 첫번째 줄과 같으나, 마지막 개행문자가 없다.
//     // 2 에서는 모든 줄의 width가 같아야한다. 첫 줄에서 width가 구해진다면 map->width에 저장해서 들고다니자.
//     // clear    
// }


int main()
{
    t_map map;

    map_init(&map);
    system("leaks a.out");
}