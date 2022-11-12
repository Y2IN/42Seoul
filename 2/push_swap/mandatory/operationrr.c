/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operationrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 02:44:16 by yje               #+#    #+#             */
/*   Updated: 2022/11/13 02:44:58 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_var *stacks)
{
	t_node	*tmp;

	tmp = pop_bottom(stacks->stack_a);
	push_top(stacks->stack_a, tmp);
	write(1, "rra\n", 4);
}

void	rrb(t_var *stacks)
{
	t_node	*tmp;

	tmp = pop_bottom(stacks->stack_b);
	push_top(stacks->stack_b, tmp);
	write(1, "rrb\n", 4);
}

void	rrr(t_var *stacks)
{
	t_node	*tmp;

	tmp = pop_bottom(stacks->stack_a);
	push_top(stacks->stack_a, tmp);
	tmp = pop_bottom(stacks->stack_b);
	push_top(stacks->stack_b, tmp);
	write(1, "rrr\n", 4);
}
