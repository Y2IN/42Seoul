/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 14:55:22 by yje               #+#    #+#             */
/*   Updated: 2022/07/22 16:21:28 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;
	unsigned int	j;

	if (s == 0)
		return ;
	i = 0;
	while (s[i])
		i++;
	j = 0;
	while (j < i)
	{
		f(j, &s[j]);
		j++;
	}
}
