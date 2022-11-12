/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 20:28:41 by yje               #+#    #+#             */
/*   Updated: 2022/11/13 00:07:31 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}


#include <stdio.h>

int main(int ac, char **av)
{
	t_var stack;

	if(ac >= 2)
	{
		init_stack(&stack);
		validate_args(ac, av, &stack);
		issort(&stack);
		indexing(&stack);
		stacking(&stack);
		// t_node *tmp = stack.stack_a->top->right;
		// while (tmp->val != 0) {
		// 	printf("%d\n", tmp->val);
		// 	tmp = tmp->right;
		// }
		// printf("abcd\n");
		swaping(&stack);
		// printf("abcde\n");
		exit(0);
	}
	return (0);
}