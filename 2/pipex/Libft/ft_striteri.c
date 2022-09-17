/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 20:52:04 by yje               #+#    #+#             */
/*   Updated: 2022/09/17 20:52:06 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;
	unsigned int	j;

	if (!s)
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
