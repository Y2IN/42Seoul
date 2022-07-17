/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 21:04:47 by yje               #+#    #+#             */
/*   Updated: 2022/07/17 21:14:42 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	unsigned char *tmp1;
	unsigned char *tmp2;

	i = 0;
	tmp1 = (unsigned char *)s1;
	tmp2 = (unsigned char *)s2;
	while (i < n)
	{
		if(tmp1[i] != tmp2[i])
			return(tmp1[i] - tmp2[i]);
		i++;
	}
	return (0);
}

#include<stdio.h>

int main()
{
	int a[2] = {214,1};
	int b[2] = {214,1};

	printf("%d", ft_memcmp(a,b, sizeof(a)));
}