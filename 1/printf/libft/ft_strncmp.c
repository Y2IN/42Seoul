/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 17:35:13 by yje               #+#    #+#             */
/*   Updated: 2022/07/29 14:56:34 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*a1;
	unsigned char	*a2;

	a1 = (unsigned char *)s1;
	a2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (*a1 != *a2)
			return (*a1 - *a2);
		if (*a1 == 0 && *a2 == 0)
			break ;
		a1++;
		a2++;
		i++;
	}
	return (0);
}
