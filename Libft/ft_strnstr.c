/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 17:49:02 by yje               #+#    #+#             */
/*   Updated: 2022/07/19 16:18:50 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
    size_t  i;
    size_t  j;
    if (*needle == 0)
        return ((char *)haystack);
    i = 0;
    j = ft_strlen(needle);
    while (i < len && haystack[i])
    {
        if (haystack[i] == *needle && i + j <= len)
        {
            if (ft_strncmp(&haystack[i], needle, j) == 0)
                return ((char *)&haystack[i]);
        }
        i++;
    }
    return (NULL);
}
