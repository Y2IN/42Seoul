/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 17:12:49 by yje               #+#    #+#             */
/*   Updated: 2022/10/03 01:02:49 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int fd_check(char *argv)
{
	int	fd;

	fd = open(argv, O_RDONLY);
    if (fd < 0)
        error("failed open.\n");
	return (fd);
	
}

int map_size_check(int fd, t_map *map)
{
    int		size;
	char	*line;

	if (fd < 0)
		error("map error : not valid file descriptor");
	size = 0;
	line = get_next_line(fd);
	map->width = ft_strlen(line) - 1;
	while (line) 
	{
		free(line);
		line = get_next_line(fd);
		size++;
	}
	free(line);
	map->height = size;
	if (map -> height <= 2)
		error("map error : not valid map size");
	return (size - 2);
}

void	free_all(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
}

void	first_line_check(char *line, t_map *map)
{
	int	width;
	int size;
	char **line_split;

	size = ft_strlen(line);
	width = 0;
	while (width < size -1)
	{
		if (line[width] != '1')
			error("map error : not surrounded top wall");
		width++;
	}
	line_split = ft_split(line, '\n');
	map->map_line = ft_strdup(line_split[0]);
	free_all(line_split);
	if (map-> width != size - 1)
		error("map error : map is not rectangul  1");
}

void middle_line_check(char *line, t_map *map)
{
	int	size;
	int i;
	char **line_split;

	size = ft_strlen(line);
	if (size - 1 != map->width || line[0] != '1' || line[size - 2] != '1')
		error("map error : not surrounded left or right wall");
	i = 0;
	while (i < size - 1)
	{
		if(!(line[i] == '1' || line[i] == '0' || line[i] == 'C' || \
			line[i] == 'E' || line[i] == 'P'))
			error("map error : invalid component");
		i++;
	}
	line_split = ft_split(line, '\n');
	map->map_line = ft_strjoin(map->map_line, line_split[0]);
	free_all(line_split);
	if (map-> width != size - 1)
		error("map error : map is not rectangul  2");
}

void last_line_check(char *line, t_map *map)
{
	int	size;
	int	i;
	char **line_split;
	
	i = 0;
	size = ft_strlen(line);
	if (map->width != size - 1)
		error("last line error");
	while(i < size -1)
	{
		if(line[i] != '1')
			break;
		i++;
	}
	line_split = ft_split(line, '\n');
	map->map_line = ft_strjoin(map->map_line, line_split[0]);
	free_all(line_split);
	if (map-> width != size - 1)
		error("map error : map is not rectangul  3");
}

void	map_init(t_map *map, char *argv)
{
    int 	fd;
    int     middle_size;
	char 	*line;

    fd = fd_check(argv);
	middle_size = map_size_check(fd, map);
	close(fd);
	fd = fd_check(argv);
	line = get_next_line(fd);
	first_line_check(line, map);
	free(line);
	while (middle_size--)
	{
		line = get_next_line(fd);
		middle_line_check(line, map);
		free(line);
	}
	line = get_next_line(fd);
	last_line_check(line, map);
	free(line);
	close(fd);
	// printf("map->map_line : %s\n", map->map_line);
}

void arg_check(char *argv)
{
	int i;
	
	i = 0;
	while (argv[i])
		i++;
	if (ft_strncmp(argv + i - 4, ".ber", 4) != 0)
		error("Error\n not vaild extension\n");
}

int	press_key(int key_code, t_map *map)
{
	if (key_code == KEY_ESC)
		exit_game(map);
	if (key_code == KEY_W)
		move_w(map);
	if (key_code == KEY_A)
		move_a(map);
	if (key_code == KEY_S)
		move_s(map);
	if (key_code == KEY_D)
		move_d(map);
	setting_img(map);
	return (0);
}

int	exit_game(t_map *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

void objs(t_map *map)
{
	int i;
	int exits;
	int p_start;

	i = 0;
	exits = 0;
	p_start = 0;
	while(map->map_line[i])
	{
		if (map->map_line[i] == 'C')
			map->all_items++;
		else if (map->map_line[i] == 'E')
			exits++;
		else if (map ->map_line[i] == 'P')
			p_start++;
		i++;
	}
	if (map->all_items < 1 || exits < 1 || p_start != 1)
		error("Error\n map error : objets error");
}

void setting_img(t_map *map)
{
	int hei;
	int wid;

	hei = 0;
	while (hei < map->height)
	{
		wid = 0;
		while (wid < map->width)
		{
			mlx_put_image_to_window(map->mlx, map->win, map->obj->ld, wid*64, hei*64);
			if (map->map_line[hei * map->width + wid] == '1')
				mlx_put_image_to_window(map->mlx, map->win, map->obj->tr, wid*64, hei*64);
			else if (map->map_line[hei * map->width + wid] == 'C')
				mlx_put_image_to_window(map->mlx, map->win, map->obj->it, wid*64, hei*64);
			else if (map->map_line[hei * map->width + wid] == 'P')
				mlx_put_image_to_window(map->mlx, map->win, map->obj->s1, wid*64 + 16, hei*64 + 16);
			else if (map->map_line[hei * map->width + wid] == 'E')
				mlx_put_image_to_window(map->mlx, map->win, map->obj->d1, wid*64 + 16, hei*64 + 16);
			wid++;
		}
		hei++;
	}
	
}
int main(int argc, char **argv)
{
    t_map map;

	if (argc != 2)
		error("error\n");
	ft_memset(&map, 0, sizeof(t_map));
	arg_check(argv[1]);
    map_init(&map, argv[1]);
	objs(&map);
	printf("clear\n");
	map.mlx = mlx_init();
	map.win = mlx_new_window(map.mlx, map.width * 64, map.height * 64, "so_long");
	obj_init(&map);
	setting_img(&map);
	mlx_hook(map.win, X_EVENT_KEY_RELEASE, 0, &press_key, &map);
	mlx_hook(map.win, X_EVENT_KEY_EXIT, 0, &exit_game, &map);
	mlx_loop(map.mlx);
	return (0);
    system("leaks so_long");
}

