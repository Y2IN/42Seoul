/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 19:55:35 by yje               #+#    #+#             */
/*   Updated: 2022/11/04 22:01:16 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

char *join_args(int ac, char **av)
{
	int i;
	int j;
	int k;
	int len;
	char *str;
	
	
	i = 0;
	k = 0;
	while (++i < ac)
		len += ft_strlen(av[i]) + 1;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 1;
	while (i < ac)
	{
		j = 0;
		while (j < ft_strlen(av[i]))
			str[k++] = av[i][j++];
		str[k++] = ' ';
		i++;
	}
	str[k] = '\0';
	return (str);
}

void validate_args(int ac, char **av)
{
	char *args;
	char **tmp;

	args = join_args(ac, av);
	// printf("%s\n", args);
	tmp = ft_split(args, ' ');
	printf("%s", tmp[0]);
	free(args);
}