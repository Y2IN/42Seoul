/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 17:12:49 by yje               #+#    #+#             */
/*   Updated: 2022/09/28 18:45:51 by yje              ###   ########.fr       */
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
    int	size;
	char *line;

	size = 0;
	line = get_next_line(fd);
	while (line) 
	{
		free(line);
		line = get_next_line(fd);
		size++;
	}
	free(line);
	map->height = size;
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
			error("first line error");
		width++;
	}
	line_split = ft_split(line, '\n');
	map->map_line = ft_strdup(line_split[0]);
	free_all(line_split);
	map->width = width;
}

void middle_line_check(char *line, t_map *map)
{
	int	size;
	int i;
	char **line_split;

	size = ft_strlen(line);
	if (size - 1 != map->width || line[0] != '1' || line[size - 2] != '1')
		error("middle line 1 error");
	i = 0;
	while (i < size - 1)
	{
		if(!(line[i] == '1' || line[i] == '0' || line[i] == 'C' || \
			line[i] == 'E' || line[i] == 'P'))
			error("middle line 2 error");
		i++;
	}
	line_split = ft_split(line, '\n');
	map->map_line = ft_strjoin(map->map_line, line_split[0]);
	free_all(line_split);
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
}

void	map_init(t_map *map, char *argv)
{
    int 	fd;
    int     map_size;
	char 	*line;

    fd = fd_check(argv);
	map_size = map_size_check(fd, map);
	close(fd);
	fd = fd_check(argv);
	line = get_next_line(fd);
	first_line_check(line, map);
	free(line);
	while (map_size--)
	{
		line = get_next_line(fd);
		middle_line_check(line, map);
		free(line);
	}
	line = get_next_line(fd);
	last_line_check(line, map);
	free(line);
	close(fd);
	printf("map->map_line : %s\n", map->map_line);
}

void arg_check(char *argv)
{
	int i;
	
	i = 0;
	while (argv[i])
		i++;
	if (ft_strncmp(argv + i - 4, ".ber", 4) != 0)
		error("not vaild extension\n");
}

int main(int argc, char **argv)
{
    t_map map;

	if (argc != 2)
		error("error\n");
	ft_memset(&map, 0, sizeof(t_map));
	arg_check(argv[1]);
    map_init(&map, argv[1]);
	mlx_init();
    system("leaks so_long");
}