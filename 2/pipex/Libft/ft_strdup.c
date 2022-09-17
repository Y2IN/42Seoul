/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 20:51:57 by yje               #+#    #+#             */
/*   Updated: 2022/09/17 20:52:00 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*cp;
	int		size;
	int		i;

	size = 0;
	while (s1[size])
		size++;
	cp = malloc(sizeof(char) * (size + 1));
	if (cp == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		cp[i] = s1[i];
		i++;
	}
	cp[i] = '\0';
	return (cp);
}
