/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 20:51:10 by yje               #+#    #+#             */
/*   Updated: 2022/07/17 21:04:28 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while(i < n)
	{
		if(((unsigned char *)s)[i] == (unsigned char)c)
			return((void *)s + i);
		i++;
	}
	return ((void *)0);
}
/*
#include<stdio.h>
int main()
{
	char *a = "123";

	printf("%s", ft_memchr(a,'2',4));
	
}
*/