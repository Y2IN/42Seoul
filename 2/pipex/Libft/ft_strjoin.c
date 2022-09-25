/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 20:52:15 by yje               #+#    #+#             */
/*   Updated: 2022/09/26 00:57:50 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_strcat(char *dest, const char *src)
{
	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*copy;
	size_t	s1_size;
	size_t	s2_size;
	size_t	size;

	if (!s1 || !s2)
		return (0);
	s1_size = ft_strlen(s1);
	s2_size = ft_strlen(s2);
	size = s1_size + s2_size;
	copy = malloc(sizeof(char) * (size + 1));
	if (!copy)
		return (0);
	copy[0] = '\0';
	ft_strcat(copy, s1);
	ft_strcat(copy + s1_size, s2);
	free(s1);
	return (copy);
}
