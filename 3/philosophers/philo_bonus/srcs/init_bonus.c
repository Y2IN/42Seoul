/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:22:04 by yje          #+#    #+#             */
/*   Updated: 2022/11/28 18:46:36 by yje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

int	init_sem(t_arg *arg)
{
	sem_unlink("fork");
	sem_unlink("print");
	arg->forks = sem_open("fork", O_CREAT, 644, arg->philo_num);
	if (!(arg->forks))
		return (1);
	arg->print = sem_open("print", O_CREAT, 644, 1);
	if (!(arg->print))
		return (1);
	return (0);
}

int	init_args(t_arg *arg, int argc, char **argv)
{
	arg->philo_num = ft_atoi(argv[1]);
	arg->time_to_die = ft_atoi(argv[2]);
	arg->time_to_eat = ft_atoi(argv[3]);
	arg->time_to_sleep = ft_atoi(argv[4]);
	arg->start_time = get_time();
	if (arg->philo_num <= 0 || arg->time_to_die < 0 || arg->time_to_eat < 0
		|| arg->time_to_sleep < 0)
		return (1);
	if (argc == 6)
	{
		arg->eat_times = ft_atoi(argv[5]);
		if (arg->eat_times <= 0)
			return (1);
		if (arg->philo_num == 1)
			arg->eat_times = 0;
	}
	if (init_sem(arg))
		return (1);
	return (0);
}

int	init_philo(t_arg *arg)
{
	int		i;

	i = 0;
	arg->philo = malloc(sizeof(t_philo) * arg->philo_num);
	if (!arg->philo)
		return (1);
	while (i < arg->philo_num)
	{
		arg->philo[i].arg = arg;
		arg->philo[i].id = i;
		arg->philo[i].last_eat_time = get_time();
		arg->philo[i].eat_count = 0;
		i++;
	}
	return (0);
}
