/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 00:18:00 by yje               #+#    #+#             */
/*   Updated: 2022/11/18 00:27:25 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	issort(t_var *stack)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (i < stack->list_size - 1)
	{
		if (stack->list[i] > stack->list[i + 1])
			count++;
		i++;
	}
	if (count == 0)
		exit(0);
}

int	find_max(t_var *stack)
{
	long	change;
	int		i;

	change = -2147483649;
	i = 0;
	while (i < stack->list_size)
	{
		if (change < stack->list[i])
			change = stack->list[i];
		i++;
	}
	i = 0;
	while (i < stack->list_size)
	{
		if (change == stack->list[i])
		{
			stack->list[i] = -2147483649;
			return (i);
		}
		i++;
	}
	return (-1);
}

void	indexing(t_var *stack)
{
	long	*indexing_list;
	int		max_i;
	int		i;

	indexing_list = (long *)malloc(sizeof(long) * stack->list_size);
	if (!indexing_list)
		print_error();
	i = stack->list_size -1;
	while (i >= 0)
	{
		max_i = find_max(stack);
		indexing_list[max_i] = i;
		i--;
	}
	free (stack->list);
	stack->list = indexing_list;
}
