/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 20:46:40 by yje               #+#    #+#             */
/*   Updated: 2022/09/17 20:46:43 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ret;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	ret = (void *)malloc(size * count);
	if (!ret)
		return (0);
	ft_memset(ret, 0, size * count);
	return (ret);
}
