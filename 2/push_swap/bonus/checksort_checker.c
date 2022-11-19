/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checksort_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 00:18:00 by yje               #+#    #+#             */
/*   Updated: 2022/11/19 21:35:23 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include <stdio.h>

int	issort(t_var *stacks)
{
	int		i;
	int		count;
	t_node	*a;

	i = 0;
	count = 0;
	a = stacks->stack_a->top->right;
	if (stacks->a_size != stacks->list_size)
		return (0);
	while (i < stacks->list_size - 1)
	{
		if (a->val > a->right->val)
			count++;
		i++;
		a = a->right;
	}
	if (count == 0)
		return (1);
	return (0);
}

void	checker(t_var *stacks)
{
	if (issort(stacks) == 1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
