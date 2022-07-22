/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 18:05:50 by minsukan          #+#    #+#             */
/*   Updated: 2022/07/11 23:00:19 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_cnt(char const *s, char c)
{
	int		flag;
	size_t	i;
	size_t	cnt;

	flag = 1;
	i = 0;
	cnt = 0;
	while (s[i])
	{
		if (s[i] == c)
			flag = 1;
		else
		{
			if (flag == 1)
				cnt++;
			flag = 0;
		}
		i++;
	}
	return (cnt);
}

static char	*ft_strcpy(char *save, char const *s, size_t start, size_t end)
{
	size_t	i;

	i = 0;
	while (start < end)
	{
		save[i] = s[start];
		i++;
		start++;
	}
	save[i] = 0;
	return (save);
}

char	**ft_free(char **save, size_t cnt)
{
	size_t		i;

	i = 0;
	while (i < cnt)
	{
		free(save[i]);
		i++;
	}
	free(save);
	return (NULL);
}

static char	**ft_putstr(char **save, char const *s, char c, size_t cnt)
{
	size_t	start;
	size_t	end;
	size_t	idx;

	start = 0;
	idx = 0;
	while (idx < cnt)
	{
		while (s[start] == c)
			start++;
		end = start;
		if (s[start] == 0)
			break ;
		while (s[end] != c && s[end] != 0)
			end++;
		save[idx] = (char *)malloc(end - start + 1);
		if (!save[idx])
			return (ft_free(save, idx));
		save[idx] = ft_strcpy(save[idx], s, start, end);
		idx++;
		start = end;
	}
	save[idx] = 0;
	return (save);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	cnt;

	if (s == NULL)
		return (NULL);
	cnt = ft_cnt(s, c);
	str = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (str == NULL)
		return (NULL);
	return (ft_putstr(str, s, c, cnt));
}
