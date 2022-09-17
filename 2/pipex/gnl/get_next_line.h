/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 20:44:55 by yje               #+#    #+#             */
/*   Updated: 2022/09/17 20:59:48 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

size_t	gnl_strlen(const char *s);
char	*gnl_strchr(const char *s, int c);
char	*gnl_strdup(const char *s1);
char	*gnl_strjoin(char const *s1, char const *s2);
char	*get_next_line(int fd);
char	*gnl_substr(char const *s, unsigned int start, size_t len);

#endif