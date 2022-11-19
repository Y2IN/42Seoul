/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:05:32 by yje               #+#    #+#             */
/*   Updated: 2022/11/19 21:38:32 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	init_stack(t_var *var)
{
	var->stack_a = (t_stack *)malloc(sizeof (t_stack));
	var->stack_b = (t_stack *)malloc(sizeof (t_stack));
	var->stack_a->top = add_new_node(0);
	var->stack_a->bottom = add_new_node(0);
	var->stack_a->top->right = var->stack_a->bottom;
	var->stack_a->bottom->left = var->stack_a->top;
	var->stack_b->top = add_new_node(0);
	var->stack_b->bottom = add_new_node(0);
	var->stack_b->top->right = var->stack_b->bottom;
	var->stack_b->bottom->left = var->stack_b->top;
	var->list = (long *)malloc(sizeof(long));
	var->a_size = 0;
	var->b_size = 0;
	var->list_size = 0;
}

t_node	*add_new_node(int n)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (0);
	node->val = n;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

void	stacking(t_var *stack)
{
	t_node	*new_node;
	int		i;

	i = 0;
	while (i < stack->list_size)
	{
		new_node = add_new_node(stack->list[i] + 1);
		if (!new_node)
			print_error();
		push_bottom(stack->stack_a, new_node);
		i++;
	}
}
