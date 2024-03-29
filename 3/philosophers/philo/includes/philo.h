/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yje <yje@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 23:29:19 by yje          #+#    #+#             */
/*   Updated: 2022/11/27 20:19:17 by yje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <sys/errno.h>

# define SUCCESS	0
# define FAIL		1

typedef struct s_philo
{
	struct s_arg	*arg;
	pthread_t		thread;
	int				id;
	int				left;
	int				right;
	long long		last_eat_time;
	int				eat_count;
}				t_philo;

typedef struct s_arg
{
	int				philo_num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				eat_times;
	int				finish;
	int				finished_eat;
	long long		start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	time;
}				t_arg;

/* utils.c */
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_atoi(const char *str);
void		sleep_until_even_eat(t_arg *arg);
long long	get_time(void);
void		spend_time(long long wait_time, t_arg *arg);

/* init.c */
int			init_mutex(t_arg *arg);
int			init_args(t_arg *arg, int argc, char **argv);
int			init_philo(t_philo **philo, t_arg *arg);

/* philo.c */
int			ph_stat_printf(t_arg *arg, int id, char *msg);
int			ph_action(t_arg *arg, t_philo *philo);
void		ph_check_finish(t_arg *arg, t_philo *philo);
int			ph_start(t_arg *arg, t_philo *philo);
void		*ph_thread(void *argv);

#endif