/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 20:16:06 by yje               #+#    #+#             */
/*   Updated: 2022/07/17 20:50:36 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	unsigned char *tmp1;
	unsigned char *tmp2;

	i = 0;
	tmp1 = (unsigned char *)dst;
	tmp2 = (unsigned char *)src;
	if (dst == src)
		return(dst);
	while (i < n)
	{
		tmp1[i] = tmp2[i];
		i++;
	}
	return (dst);
}
/*
#include <stdio.h>

int main(void)
{
        char src[32] = "";
        char dest[32] = "";
 
        printf("%s\n", dest);
      
        ft_memcpy( dest, src, sizeof(src));
        printf( "%s\n", dest);
        
        return 0;
}
*/