/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 20:28:41 by yje               #+#    #+#             */
/*   Updated: 2022/11/19 21:42:08 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	print_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	main(int ac, char **av)
{
	t_var	stack;

	if (ac >= 2)
	{
		init_stack(&stack);
		validate_args(ac, av, &stack);
		stacking(&stack);
		input(&stack);
		checker(&stack);
		exit(0);
	}
	return (0);
}
