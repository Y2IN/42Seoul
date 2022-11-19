/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 19:55:35 by yje               #+#    #+#             */
/*   Updated: 2022/11/19 21:40:52 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	size_check(char const *str, char c)
{
	int	size;
	int	i;

	i = 0;
	size = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] != '\0')
			size++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (size);
}

char	*join_args(int ac, char **av)
{
	int		i;
	int		j;
	int		k;
	int		len;
	char	*str;

	i = 0;
	k = 0;
	len = 0;
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

void	check_overlap(t_var *stack, int check)
{
	int		i;
	long	*tmp;

	i = 0;
	while (i < stack->list_size)
	{
		if (stack->list[i] == check)
			print_error();
		i++;
	}
	stack->list_size++;
	tmp = (long *)malloc(sizeof(long) * stack->list_size);
	if (!tmp)
		print_error();
	if (stack->list_size == 1)
		tmp[0] = check;
	else
	{
		i = -1;
		while (++i < stack->list_size -1)
			tmp[i] = stack->list[i];
		tmp[i] = check;
	}
	free(stack->list);
	stack->list = tmp;
}

void	validate_args(int ac, char **av, t_var *stack)
{
	char	*args;
	char	**tmp;
	int		i;
	int		tmp_size;
	t_node	*new_node;

	i = 0;
	args = join_args(ac, av);
	tmp = ft_split(args, ' ');
	tmp_size = size_check(args, ' ');
	free (args);
	while (i < tmp_size)
	{
		if (!is_number(tmp[i]))
			print_error();
		new_node = add_new_node(ft_atoi(tmp[i]));
		free(tmp[i]);
		check_overlap(stack, new_node->val);
		i++;
		free(new_node);
	}
	free(tmp);
	stack->a_size = stack->list_size;
}
