/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 23:19:15 by yje               #+#    #+#             */
/*   Updated: 2022/11/11 01:04:00 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include<stdio.h>

void issort(t_var *stack)
{
    int i;
    int count;

    i = 0;
    count = 0;
	printf("%d\n", stack->list_size);
    while(i < stack->list_size)
    {
        if (stack->list[i] > stack->list[i + 1])
            count++;
		i++; 
    }
	printf("-------------------------\n");
	printf("%d\n", count);
	if (count == 1)
		exit(0);
}

int find_max(t_var *stack)
{
	long change;
	int i;

	change = -2147483649;
	i = 0;

	while (i < stack->list_size)
	{
		if (change < stack->list[i])
			change = stack->list[i];
		i++;
	}
	i = 0;
	while(i < stack->list_size)
	{
		if (change == stack->list[i])
		{
			stack->list[i] = -2147483649;
			return (i+1);
		}
		i++;
	}
	return (-1);
}

void indexing(t_var *stack)
{
	long *indexing_list;
	int max_i;
	int i;

	indexing_list = (long *)malloc(sizeof(long) * stack->list_size);
	if(!indexing_list)
		print_error();
	i = stack->list_size ;
	while (i > 0)
	{
		max_i = find_max(stack);
		printf("max_i : [%d]\n", max_i);
		indexing_list[max_i] = i;
		i--;
	}
	free(stack->list);
	stack->list = indexing_list;
}
