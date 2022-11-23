/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:56:52 by yje               #+#    #+#             */
/*   Updated: 2022/11/23 16:45:03 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>

typedef struct s_philo
{
	/* data */
}	t_philo;

typedef struct s_argu {
	int	number_of_philosophers;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int philosopher_must_eat;
}	t_argu;

/* utils.c */
int	ft_atoi(const char *str);

/* main.c */
int	print_error(char *msg);
int args_init(t_argu *arg, int argc, char **argv);
// int init_philosophers(t_argu arg, int argc, char **argv);
int main(int argc, char **argv);



#endif