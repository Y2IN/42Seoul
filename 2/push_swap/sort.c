/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:59:04 by yje               #+#    #+#             */
/*   Updated: 2022/11/12 23:33:12 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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


void same_rotate(t_var *stack, int *a, int *b)
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

void	b_rotate(t_var *stacks, int a)
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

void	sort_big_last(t_var *stacks)
{
	int	min_location;

	min_location = find_a_min(stacks);
	while (min_location)
	{
		if (min_location > 0)
		{
			ra(stacks);
			min_location--;
		}
		else
		{
			rra(stacks);
			min_location++;
		}
	}
}

void sort_all(t_var *stack)
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
	printf("here\n");
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

int	get_stack_min(t_var *stacks)
{
	int res;
	int count;
	t_node *stack;

	stack = stacks->stack_a->top->right;
	res = stack->val;
	count = 0;

	while(count < stacks->a_size - 1)
	{
		if (res > stack->right->val)
			res = stack->right->val;
		stack = stack->right;
		count++;
	}
	return (res);
}

int find_a_min(t_var *stacks)
{
	int res;
	int tmp;
	int i;
	t_node 	*stack_a;

	res = 0;
	tmp = 0;
	stack_a = stacks->stack_a->top->right;
	i = get_stack_min(stacks);
	while (res < stacks->a_size)
	{
		tmp = stack_a->val;
		if (tmp == i)
			break;
		res++;
		stack_a = stack_a->right;
	}
	if (res >= (stacks->a_size + 1) / 2)
		res = (stacks->a_size - res) * -1;
	return(res);
}

int	get_stack_max(t_var *stacks)
{
	int res;
	int count;
	t_node *stack;

	stack = stacks->stack_a->top->right;
	res = stack->val;
	count = 0;
	while(count < stacks->a_size - 1)
	{
		if (res < stack->right->val)
			res = stack->right->val;
		stack = stack->right;
		count++;
	}
	return (res);
}

int find_a_max(t_var *stacks)
{
	int res;
	int tmp;
	int i;
	t_node 	*stack_a;

	res = 0;
	tmp = 0;
	stack_a = stacks->stack_a->top->right;
	i = get_stack_max(stacks);
	while (res < stacks->a_size)
	{
		tmp = stack_a->val;
		if (tmp == i)
			break;
		res++;
		stack_a = stack_a->right;
	}
	if (res >= (stacks->a_size + 1) / 2)
		res = (stacks->a_size - res) * -1;
	return(res);
}

int find_a_mid(int n, t_var *stacks)
{
	int res;
	int i;
	t_node 	*stack_a;

	res = 1;
	i = 0;
	stack_a = stacks->stack_a->top->right;
	while (res < stacks->a_size)
	{
		if (stack_a->right->val == 0)
			return (0);
		if (n > stack_a->val && n < stack_a->right->val)
			break;
		res++;
		stack_a = stack_a->right;
		i++;
	}
	if (res >= (stacks->a_size + 1) / 2)
		res = (stacks->a_size - res) * -1;
	return(res);
}

int find_a(int n, t_var *stack)
{
	int res;

	if (n < get_stack_min(stack))
		res = find_a_min(stack);
	else if( n > get_stack_max(stack))
		res = find_a_max(stack);
	else
		res = find_a_mid(n, stack);
	return (res);
}

int	get_bigger(int a, int b, int a_loc, int b_loc)
{
	if (a < 0)
		a = a * -1;
	if (b < 0)
		b = b * -1;
	if (a_loc < 0)
		a_loc = a_loc * -1;
	if (b_loc < 0)
		b_loc = b_loc * -1;
	if (a + b > a_loc + b_loc)
		return (1);
	else
		return (0);
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
		a_location = find_a(num, stack);
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
