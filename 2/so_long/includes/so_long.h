/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 17:13:24 by yje               #+#    #+#             */
/*   Updated: 2022/09/26 00:29:43 by yje              ###   ########.fr       */
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

typedef struct  s_map
{
    int     width;
    int     height;
    char    *map_line;
}               t_map;

size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char    *get_next_line(int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void    error(char *msg);
int     fd_check(char *argv);


#endif
