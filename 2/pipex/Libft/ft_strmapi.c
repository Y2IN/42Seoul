/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 20:52:45 by yje               #+#    #+#             */
/*   Updated: 2022/09/17 20:52:46 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	j;
	char			*map_s;

	if (!s || !f)
		return (0);
	i = 0;
	while (s[i])
		i++;
	map_s = (char *)malloc(sizeof(char) * (i + 1));
	if (map_s == 0)
		return (0);
	j = 0;
	while (j < i)
	{
		map_s[j] = f(j, s[j]);
		j++;
	}
	map_s[j] = '\0';
	return (map_s);
}
