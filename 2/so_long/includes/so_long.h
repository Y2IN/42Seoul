/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 17:13:24 by yje               #+#    #+#             */
/*   Updated: 2022/10/03 01:08:00 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

#include "../mlx/mlx.h"
#include "../libft/libft.h"
#include "../gnl/get_next_line.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# define X_EVENT_KEY_PRESS			2
# define X_EVENT_KEY_RELEASE		3
# define X_EVENT_KEY_EXIT			17

# define KEY_ESC					53
# define KEY_W						13
# define KEY_A						0
# define KEY_S						1
# define KEY_D						2

typedef struct s_obj
{
	void	*ld;
	void	*tr;
	void	*it;
	void	*d1;
	void	*d2;
	void	*s1;
	void	*s4;
	void	*s7;
	void	*s10;
}				t_obj;

typedef struct s_map
{
	int				x;
	int				y;
	int				width;
	int				height;
	int				all_items;
	int				c_items;
	int				walk_cnt;
	char			*map_line;
	void			*mlx;
	void			*win;
	struct s_obj	*obj;
}					t_map;


char    *get_next_line(int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void    error(char *msg);
int     fd_check(char *argv);
void    move_d(t_map *map);
void    move_s(t_map *map);
void    move_a(t_map *map);
void    move_w(t_map *map);
void    obj_init(t_map *map);
int     press_key(int key_code, t_map *map);
void    objs(t_map *map);
int     exit_game(t_map *game);
void    setting_img(t_map *map);
#endif
