/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push_checker.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:06:30 by yje               #+#    #+#             */
/*   Updated: 2022/11/19 20:02:59 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	push_top(t_stack *stack, t_node *new_node)
{
	t_node	*tmp;
	t_node	*top;

	top = stack->top;
	tmp = top->right;
	top->right = new_node;
	tmp->left = new_node;
	new_node->left = top;
	new_node->right = tmp;
}

void	push_bottom(t_stack *stack, t_node *new_node)
{
	t_node	*tmp;
	t_node	*bottom;

	bottom = stack->bottom;
	tmp = bottom->left;
	bottom->left = new_node;
	tmp->right = new_node;
	new_node->right = bottom;
	new_node->left = tmp;
}
