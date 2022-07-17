/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 19:51:16 by yje               #+#    #+#             */
/*   Updated: 2022/07/17 20:04:03 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t i;
	
	i = 0;
	if (n == 0)
		return ;
	while (i < n)
	{
		*(unsigned char *)(s+i) = 0;
		i++; 
	}
}
/*
#include <stdio.h>
int main(void)
{
	char str[100] = "123456789";
	
		printf("%s\n",str);
		ft_bzero(str, 1);
		for(int i = 0; i<10; i++)
			printf("%c",str[i]);
			
}
*/