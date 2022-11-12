/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 16:33:31 by yje               #+#    #+#             */
/*   Updated: 2022/11/13 02:45:35 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_var *stacks)
{
	t_node	*tmp1;
	t_node	*tmp2;

	tmp1 = pop_top(stacks->stack_a);
	tmp2 = pop_top(stacks->stack_a);
	push_top(stacks->stack_a, tmp1);
	push_top(stacks->stack_a, tmp2);
	write(1, "sa\n", 3);
}

void	sb(t_var *stacks)
{
	t_node	*tmp1;
	t_node	*tmp2;

	tmp1 = pop_top(stacks->stack_b);
	tmp2 = pop_top(stacks->stack_b);
	push_top(stacks->stack_b, tmp1);
	push_top(stacks->stack_b, tmp2);
	write(1, "sb\n", 3);
}

void	ss(t_var *stacks)
{
	t_node	*tmp1;
	t_node	*tmp2;

	tmp1 = pop_top(stacks->stack_a);
	tmp2 = pop_top(stacks->stack_a);
	push_top(stacks->stack_a, tmp1);
	push_top(stacks->stack_a, tmp2);
	tmp1 = pop_top(stacks->stack_b);
	tmp2 = pop_top(stacks->stack_b);
	push_top(stacks->stack_b, tmp1);
	push_top(stacks->stack_b, tmp2);
	write(1, "ss\n", 3);
}
