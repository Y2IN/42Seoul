/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 20:03:21 by yje               #+#    #+#             */
/*   Updated: 2022/11/19 21:47:24 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	command_check(char *in, t_var *stacks)
{
	if (!ft_strcmp (in, "sa\n"))
		sa (stacks);
	else if (!ft_strcmp (in, "sb\n"))
		sb (stacks);
	else if (!ft_strcmp (in, "ss\n"))
		ss (stacks);
	else if (!ft_strcmp (in, "pa\n"))
		pa (stacks);
	else if (!ft_strcmp (in, "pb\n"))
		pb (stacks);
	else if (!ft_strcmp (in, "ra\n"))
		ra (stacks);
	else if (!ft_strcmp (in, "rb\n"))
		rb (stacks);
	else if (!ft_strcmp (in, "rr\n"))
		rr (stacks);
	else if (!ft_strcmp (in, "rra\n"))
		rra (stacks);
	else if (!ft_strcmp (in, "rrb\n"))
		rrb (stacks);
	else if (!ft_strcmp (in, "rrr\n"))
		rrr (stacks);
}

void	input(t_var *stacks)
{
	char	*in;

	while (1)
	{
		in = get_next_line(0);
		if (!in)
			break ;
		command_check (in, stacks);
		free (in);
	}
}
