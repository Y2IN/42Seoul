/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 20:50:02 by yje               #+#    #+#             */
/*   Updated: 2022/09/17 20:50:03 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*uc;

	uc = s;
	while (n-- != 0)
	{
		if (*uc == (unsigned char)c)
			return ((void *)uc);
		uc++;
	}
	return (0);
}
