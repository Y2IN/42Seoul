/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 15:20:33 by yje               #+#    #+#             */
/*   Updated: 2022/07/22 16:15:17 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*null_return(void)
{
	char	*ret;

	ret = malloc(sizeof(char));
	if (ret == 0)
		return (NULL);
	ret[0] = '\0';
	return (ret);
}

int	lencheck(char const *s, unsigned int start, size_t len)
{
	if ((ft_strlen(s) - start) < len)
		return ((ft_strlen(s) - start));
	else
		return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*sub;

	i = 0;
	j = 0;
	if (s == 0)
		return (0);
	if (ft_strlen(s) < start)
		return (null_return());
	sub = (char *)malloc(sizeof(char) * (lencheck(s, start, len) + 1));
	if (sub == 0)
		return (0);
	while (s[i])
	{
		if (i >= start && j < len)
		{
			sub[j] = s[i];
			j++;
		}
		i++;
	}
	sub[j] = '\0';
	return (sub);
}
