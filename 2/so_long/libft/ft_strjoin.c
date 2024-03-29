/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 15:26:08 by yje               #+#    #+#             */
/*   Updated: 2022/10/04 20:59:24 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*copy;
	int		i;
	int		j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	j = 0;
	copy = (char *)ft_calloc(sizeof(char), (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (copy == 0)
		return (0);
	while (s1[i] != '\0')
	{
		copy[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		copy[i + j] = s2[j];
		j++;
	}
	free(s1);
	return (copy);
}
