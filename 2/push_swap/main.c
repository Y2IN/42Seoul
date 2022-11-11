/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 20:28:41 by yje               #+#    #+#             */
/*   Updated: 2022/11/11 16:00:28 by yje              ###   ########.fr       */
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
	int i;
	t_var stack;

	if(ac>=2)
	{
		i = 1;
		validate_args(ac, av, &stack);
		issort(&stack);
		indexing(&stack);
		stacking(&stack);
		swaping(&stack);
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
	}
	return (0);
}