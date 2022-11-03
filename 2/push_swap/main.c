/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 20:28:41 by yje               #+#    #+#             */
/*   Updated: 2022/11/03 16:31:25 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_var *var)
{
	var->stack_a = (t_stack *)malloc(sizeof(t_stack));
	var->stack_b = (t_stack *)malloc(sizeof(t_stack));
	var->stack_a->top = get_new_node(0);
	var->stack_a->bottom = get_new_node(0);
	var->stack_a->top->right = var->stack_a->bottom;
	var->stack_a->bottom->left = var->stack_a->top;
	var->stack_b->top = get_new_node(0);
	var->stack_b->bottom = get_new_node(0);
	var->stack_b->top->right = var->stack_b->bottom;
	var->stack_b->bottom->left = var->stack_b->top;
	var->list = (int *)malloc(sizeof(int));
	var->list_size = 0;
	var->a_size = 0;
	var->b_size = 0;
}