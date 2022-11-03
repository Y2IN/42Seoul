/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:19:19 by yje               #+#    #+#             */
/*   Updated: 2022/11/03 16:38:49 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>

// typedef struct s_node
// {
// 	int				val;
// 	struct s_node	*left;
// 	struct s_node	*right;
// }	t_node;

// typedef struct s_stack
// {
// 	struct s_node	*top;
// 	struct s_node	*bottom;
// }	t_stack;

typedef struct s_var
{
	struct s_stack	*stack_a;
	struct s_stack	*stack_b;
	int	list;
	int list_size;
	int a_size;
	int b_size;
	
	
} t_var;

#endif
