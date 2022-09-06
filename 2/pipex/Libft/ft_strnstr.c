/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 20:07:54 by chanwjeo          #+#    #+#             */
/*   Updated: 2022/09/06 18:04:33 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (i + j < len)
	{
		if (haystack[i])
		{
			if (haystack[i + j] == needle[j])
				j++;
			else
				j = 0;
			if (!needle[j])
				return ((char *)(haystack + i));
		}
		else
			return (0);
		if (j == 0)
			i++;
	}
	return (0);
}
