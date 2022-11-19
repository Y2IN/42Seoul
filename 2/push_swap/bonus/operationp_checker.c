/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operationp_checker.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:42:01 by yje               #+#    #+#             */
/*   Updated: 2022/11/19 20:39:10 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	pa(t_var *stacks)
{
	t_node	*tmp1;

	if (stacks->stack_b->top->right != 0)
	{
		tmp1 = pop_top(stacks->stack_b);
		push_top(stacks->stack_a, tmp1);
		stacks->b_size--;
		stacks->a_size++;
	}
}

void	pb(t_var *stacks)
{
	t_node	*tmp1;

	if (stacks->stack_a->top->right != 0)
	{
		tmp1 = pop_top(stacks->stack_a);
		push_top(stacks->stack_b, tmp1);
		stacks->a_size--;
		stacks->b_size++;
	}
}
