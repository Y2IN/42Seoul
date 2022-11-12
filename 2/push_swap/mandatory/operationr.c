/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operationr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:45:34 by yje               #+#    #+#             */
/*   Updated: 2022/11/13 00:11:07 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_var *stacks)
{
	t_node	*tmp;
	
	tmp = pop_top(stacks->stack_a);
	push_bottom(stacks->stack_a, tmp);
	write(1, "ra\n", 3);
}

void	rb(t_var *stacks)
{
	t_node	*tmp;
	
	tmp = pop_top(stacks->stack_b);
	push_bottom(stacks->stack_b, tmp);
	write(1, "rb\n", 3);
}

void	rr(t_var *stacks)
{
	t_node	*tmp;
	
	tmp = pop_top(stacks->stack_a);
	push_bottom(stacks->stack_a, tmp);
	tmp = pop_top(stacks->stack_b);
	push_bottom(stacks->stack_b, tmp);
	write(1, "rr\n", 3);
}

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