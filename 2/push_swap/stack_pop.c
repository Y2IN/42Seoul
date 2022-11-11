/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:05:58 by yje               #+#    #+#             */
/*   Updated: 2022/11/09 15:13:44 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
