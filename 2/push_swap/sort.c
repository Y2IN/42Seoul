/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:59:04 by yje               #+#    #+#             */
/*   Updated: 2022/11/11 18:50:22 by yje              ###   ########.fr       */
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

void sort_three(t_var *stack)
{
	int top;
	int middle;
	int bottom;

	top = stack->stack_a->top->right->val;
	middle = stack->stack_a->top->right->right->val;
	bottom = stack->stack_a->bottom->left->val;
	
	if(middle > top && middle > bottom && bottom > top)
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
	else if(top > middle && bottom > middle && top > bottom)
		ra(stack);
	else if(middle>top && middle > bottom && top>bottom)
		rra(stack);
}

void sort_args(t_var *stack)
{
	int a;
	int b;

	devide_pivot(stack);
	while (stack->a_size > 3)
		pb(stack);
	if (stack->a_size == 2)
	{
		if(stack->stack_a->top->right->val \
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
		
		
	}
}
void	devide_pivot(t_var *stack)
{
	t_node	*tmp;
	int count;
	int p1;
	int p2;

	p1 = stack->max_size / 3;
	p2 = (stack->max_size / 3) * 2;
	count = 0;

	while (count < stack->max_size)
	{
		tmp = pop_top(stack->stack_a);
		if(tmp->val < p2)
		{
			push_top(stack->stack_a, tmp);
			pb(stack);
			if(tmp->val < p1)
				rb(stack);
		}
		else
		{
			push_top(stack->stack_a, tmp);
			ra(stack);
		}
		count++;
	}
}

int find_a(int n, t_var *stack)
{
		
}

void	min_rotate(t_var *stack, int *a, int *b)
{
	int i;
	int num;
	int a_location;
	int b_location;
	t_node	*b_node;
	
	i = 0;
	b_node = stack->stack_b->top->right;
	while(i < stack->b_size)
	{
		num = b_node->val;
		a_location = find_a(num, stack); //
		if (i >= (stack->b_size + 1) / 2)
			b_location = (stack->b_size - i) * -1;
		else
			b_location = i;
		if (i == 0 || get_bigger(*a, *b, a_location, b_location)) //
		{
			*a = a_location;
			*b = b_location;
		}	
		b_node = b_node->right;
		i++;
	}
}
