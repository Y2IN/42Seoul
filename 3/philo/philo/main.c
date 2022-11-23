/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:47:18 by yje               #+#    #+#             */
/*   Updated: 2022/11/23 17:01:49 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_error(char *msg)
{
	printf("Error: %s\n", msg);
	return (0);	
}

int args_init(t_argu *arg, int argc, char **argv)
{
	arg->number_of_philosophers = ft_atoi(argv[1]);
	arg->time_to_die = ft_atoi(argv[2]);
	arg->time_to_eat = ft_atoi(argv[3]);
	arg->time_to_sleep = ft_atoi(argv[4]);
	if (arg->number_of_philosophers <= 0 || arg->time_to_die < 0 
		|| arg->time_to_eat < 0 || arg->time_to_sleep < 0)
		return (1);
	if (argc == 6)
	{
		arg->philosopher_must_eat = ft_atoi(argv[5]);
		if (arg->philosopher_must_eat <= 0)
			return (1);	
	}
	return (0);
}

// int philo_init(t_philo *philo, t_argu *arg)
// {
	
// }

int main(int argc, char **argv)
{
	t_argu	arg;
	t_philo *philo;
	
	if (argc != 5 && argc != 6)
		return (print_error("Invalid argument"));
	memset(&arg, 0, sizeof(t_argu));
	if (args_init(&arg, argc, argv))
		return(print_error("arguments init failed"));
	// if (philo_init(&philo, &arg))
	// 	return(print_error("philos init failed"));
	// if (philo_start(&arg, philo))
	// 	return (print_error("philo start failed"));
	return (0);
}