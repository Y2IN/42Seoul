/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operationrr_checker.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 02:44:16 by yje               #+#    #+#             */
/*   Updated: 2022/11/19 20:38:44 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rra(t_var *stacks)
{
	t_node	*tmp;

	tmp = pop_bottom(stacks->stack_a);
	push_top(stacks->stack_a, tmp);
}

void	rrb(t_var *stacks)
{
	t_node	*tmp;

	tmp = pop_bottom(stacks->stack_b);
	push_top(stacks->stack_b, tmp);
}

void	rrr(t_var *stacks)
{
	t_node	*tmp;

	tmp = pop_bottom(stacks->stack_a);
	push_top(stacks->stack_a, tmp);
	tmp = pop_bottom(stacks->stack_b);
	push_top(stacks->stack_b, tmp);
}
