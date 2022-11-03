/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operationp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:42:01 by yje               #+#    #+#             */
/*   Updated: 2022/11/03 18:45:04 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_var *stacks)
{
	int tmp1;

	tmp1 = pop_top(stacks->stack_b);
	push_top(stacks->stack_a, tmp1);
	write(1, "pa\n", 3);
}

void	pb(t_var *stacks)
{
	int tmp1;

	tmp1 = pop_top(stacks->stack_a);
	push_top(stacks->stack_a, tmp1);
	write(1, "pb\n", 3);
}