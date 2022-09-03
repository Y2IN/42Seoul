/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 21:17:05 by yje               #+#    #+#             */
/*   Updated: 2022/07/29 14:45:51 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*tmp1;
	unsigned char	*tmp2;

	tmp1 = (unsigned char *)dst;
	tmp2 = (unsigned char *)src;
	if (dst == src || len == 0)
		return (dst);
	if (dst < src)
	{
		while (len--)
		{
			*tmp1 = *tmp2;
			tmp1++;
			tmp2++;
		}
	}
	else
	{
		while (len--)
			*(tmp1 + len) = *(tmp2 + len);
	}
	return (dst);
}
