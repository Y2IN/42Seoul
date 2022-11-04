/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 20:28:41 by yje               #+#    #+#             */
/*   Updated: 2022/11/04 21:24:10 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_node	*pop_top(t_stack *stack)
{
	t_node	*top;
	t_node	*tmp;

	top = stack->top;
	if(top->right == stack->bottom)
		return (0);
	tmp = top->right;
	tmp->right->left = top;
	top->right = tmp->right;
	tmp->left = NULL;
	tmp->right = NULL;
	return(tmp);
}

t_node	*pop_bottom(t_stack *stack)
{
	t_node	*bottom;
	t_node	*tmp;

	bottom = stack->bottom;
	if(bottom->left == stack->top)
		return (0);
	tmp = bottom->left;
	tmp->left->right = bottom;
	bottom->left = tmp->left;
	tmp->left = NULL;
	tmp->right = NULL;
	return(tmp);
}

void push_top(t_stack *stack, t_node *new_node)
{
	t_node *tmp;
	t_node *top;

	top = stack->top;
	tmp = top->right;
	top->right = new_node;
	tmp->left = new_node;
	new_node->left = top;
	new_node->right = tmp;	
}

void push_bottom(t_stack *stack, t_node *new_node)
{
	t_node *tmp;
	t_node *bottom;

	bottom = stack->bottom;
	tmp = bottom->left;
	bottom->left = new_node;
	tmp->right = new_node;
	new_node->right = bottom;
	new_node->left = tmp;	
}

#include <stdio.h>

int main(int ac, char **av)
{
	int i;
	t_var var;

	i = 1;
	validate_args(ac, av);
	// init_stack(&var);
	// while (i < argc)
	// {
	// 	// push_top(var.stack_a, add_new_node(atoi(argv[i])));
	// 	// push_top(var.stack_b, add_new_node(atoi(argv[i])));
	// 	i++;
	// }
	// pb(&var);
	// while (i > 1) {
	// 	// printf("a : %d\n", pop_top(var.stack_a)->val);
	// 	// printf("b: %d\n", pop_top(var.stack_b)->val);
	// 	i--;
	// }
	return (0);
}