/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:47:50 by yje               #+#    #+#             */
/*   Updated: 2022/12/09 18:12:18 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	monitoring(t_argu *arg, t_philo *philo)
{
	int i;
	
}
int	simulation_start(t_argu *arg, t_philo *philo)
{
	int		i;

	i = 0;
	arg->start_time = get_time();//
	while (i < arg->number_of_philosophers)
	{	
		philo[i].last_eat_time = get_time();
		if (pthread_create(&(philo[i].thread), NULL, ph_thread, &(philo[i])))
			return (1);
		i++;
	}
	monitoring(arg, philo);
	i = 0;
	while (i < arg->number_of_philosophers)
		pthread_join(philo[i++].thread, NULL);
	return (0);
}

void	*ph_thread(void *argv)
{
	t_argu		*arg;
	t_philo		*philo;

	philo = argv;
	arg = philo->arg;
	if (philo->id % 2 == 0)
		usleep(800);
	return (0);
}

