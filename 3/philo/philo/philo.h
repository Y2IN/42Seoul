/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:56:52 by yje               #+#    #+#             */
/*   Updated: 2022/12/09 18:12:22 by yje              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define TRUE 1
# define FALSE -1

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <sys/time.h>
# include <stdlib.h>
# include <limits.h>
# include <pthread.h>
// # include <sys/errno.h>


typedef struct s_philo
{
	struct t_argu	*arg;
	pthread_t		thread;
	long long		last_eat_time;
	int				id;
	int				eat_count;
	int				left;
	int				right;
}	t_philo;

typedef struct s_argu {
	int	number_of_philosophers;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int philosopher_must_eat;
	int	start_time;
	pthread_mutex_t	*forks;
}	t_argu;

/* utils.c */
int			ft_atoi(const char *str);
long long	get_time(void);

/* main.c */
int	print_error(char *msg);
int args_init(t_argu *arg, int argc, char **argv);

int init_philosophers(t_argu arg, int argc, char **argv);
int main(int argc, char **argv);

/* philo.c */
int	philo_start(t_argu *arg, t_philo *philo);

#endif