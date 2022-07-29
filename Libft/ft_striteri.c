/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 14:55:22 by yje               #+#    #+#             */
/*   Updated: 2022/07/29 19:10:01 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;
	unsigned int	j;

	if (s == NULL)
		return ;
	i = ft_strlen(s);
	j = 0;
	while (j < i)
	{
		f(j, &s[j]);
		j++;
	}
}
