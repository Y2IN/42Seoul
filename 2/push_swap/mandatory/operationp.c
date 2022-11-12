/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operationp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:42:01 by yje               #+#    #+#             */
/*   Updated: 2022/11/11 17:46:10 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_var *stacks)
{
	t_node *tmp1;
	
	if(stacks->stack_b->top->right != 0)
	{
		tmp1 = pop_top(stacks->stack_b);
		push_top(stacks->stack_a, tmp1);
		stacks->b_size--;
		stacks->a_size++;
		write(1, "pa\n", 3);
	}
}

void	pb(t_var *stacks)
{
	t_node *tmp1;
	
	if(stacks->stack_a->top->right != 0)
	{
		tmp1 = pop_top(stacks->stack_a);
		push_top(stacks->stack_b, tmp1);
		stacks->a_size--;
		stacks->b_size++;
		write(1, "pb\n", 3);
	}
}
