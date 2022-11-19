/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operationr_checker.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:45:34 by yje               #+#    #+#             */
/*   Updated: 2022/11/19 20:39:13 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ra(t_var *stacks)
{
	t_node	*tmp;

	tmp = pop_top(stacks->stack_a);
	push_bottom(stacks->stack_a, tmp);
}

void	rb(t_var *stacks)
{
	t_node	*tmp;

	tmp = pop_top(stacks->stack_b);
	push_bottom(stacks->stack_b, tmp);
}

void	rr(t_var *stacks)
{
	t_node	*tmp;

	tmp = pop_top(stacks->stack_a);
	push_bottom(stacks->stack_a, tmp);
	tmp = pop_top(stacks->stack_b);
	push_bottom(stacks->stack_b, tmp);
}
