/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:05:32 by yje               #+#    #+#             */
/*   Updated: 2022/11/09 15:41:52 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void init_stack(t_var *var)
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
}

t_node	*add_new_node(int n)
{
	t_node *node;
	
	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (0);
	node->val = n;
	node->left = NULL;
	node->right = NULL;
	return (node);
}