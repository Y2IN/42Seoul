/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 02:46:14 by yje               #+#    #+#             */
/*   Updated: 2022/11/13 02:56:56 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_rotate(t_var *stacks, int a)
{
	while (a)
	{
		if (a > 0)
		{
			ra(stacks);
			a--;
		}
		else
		{
			rra(stacks);
			a++;
		}
	}
}

void	b_rotate(t_var *stacks, int b)
{
	while (b)
	{
		if (b > 0)
		{
			rb(stacks);
			b--;
		}
		else
		{
			rrb(stacks);
			b++;
		}
	}
}

void	same_rotate(t_var *stack, int *a, int *b)
{
	while (*a && *b && (*a > 0 && *b > 0))
	{
		rr(stack);
		*a = *a - 1;
		*b = *b - 1;
	}
	while (*a && *b && (*a < 0 && *b < 0))
	{
		rrr(stack);
		*a = *a + 1;
		*b = *b + 1;
	}
}

void	min_rotate(t_var *stack, int *a, int *b)
{
	int		i;
	int		num;
	int		a_location;
	int		b_location;
	t_node	*b_node;

	i = 0;
	b_node = stack->stack_b->top->right;
	while (i < stack->b_size)
	{
		num = b_node->val;
		a_location = find_a(num, stack);
		if (i >= (stack->b_size + 1) / 2)
			b_location = (stack->b_size - i) * -1;
		else
			b_location = i;
		if (i == 0 || get_bigger(*a, *b, a_location, b_location))
		{
			*a = a_location;
			*b = b_location;
		}	
		b_node = b_node->right;
		i++;
	}
}
