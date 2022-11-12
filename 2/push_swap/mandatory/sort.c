/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:59:04 by yje               #+#    #+#             */
/*   Updated: 2022/11/13 03:00:50 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swaping(t_var *stack)
{
	stack->a_size = stack->list_size;
	if (stack->list_size == 2)
		sa(stack);
	if (stack->list_size == 3)
		sort_three(stack);
	else
		sort_all(stack);
}

void	sort_three(t_var *stack)
{
	int		top;
	int		middle;
	int		bottom;

	top = stack->stack_a->top->right->val;
	middle = stack->stack_a->top->right->right->val;
	bottom = stack->stack_a->bottom->left->val;
	if (middle > top && middle > bottom && bottom > top)
	{
		sa(stack);
		ra(stack);
	}
	else if (top > middle && bottom > middle && bottom > top)
		sa(stack);
	else if (top > middle && middle > bottom && top > bottom)
	{
		sa(stack);
		rra(stack);
	}
	else if (top > middle && bottom > middle && top > bottom)
		ra(stack);
	else if (middle > top && middle > bottom && top > bottom)
		rra(stack);
}

void	sort_all(t_var *stack)
{
	int		a;
	int		b;

	devide_pivot(stack);
	while (stack->a_size > 3)
		pb(stack);
	if (stack->a_size == 2)
	{
		if (stack->stack_a->top->right->val \
		> stack->stack_a->bottom->left->val)
			sa(stack);
	}
	if (stack->a_size == 3)
		sort_three(stack);
	while (stack->b_size)
	{
		a = 0;
		b = 0;
		min_rotate(stack, &a, &b);
		same_rotate(stack, &a, &b);
		a_rotate(stack, a);
		b_rotate(stack, b);
		pa(stack);
	}
	sort_big_last(stack);
}
