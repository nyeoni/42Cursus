/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:18:25 by nkim              #+#    #+#             */
/*   Updated: 2022/05/06 13:44:35 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

# define ERROR_FLAG -1
# define SUCCESS_FLAG 0
# define TRUE 1
# define FALSE 0

typedef struct s_manager	t_manager;
typedef struct s_philo
{
	pthread_t				thread;
	pthread_mutex_t			mutex;
	int						id;
	int						right;
	int						left;
	long long				start_eat_ms_time;
	long long				last_eat_ms_time;
	long long				start_sleep_ms_time;
	int						num_of_eat;
	t_manager				*manager;
}							t_philo;

typedef struct s_manager
{
	int						number_of_philos;
	int						time_to_die;
	int						time_to_eat;
	int						time_to_sleep;
	int						num_of_time_must_eat;
	int						finish;
	pthread_mutex_t			finish_mutex;
	long long				start_ms_time;
	t_philo					*philos;
	pthread_mutex_t			*fork;
	pthread_mutex_t			print;
}							t_manager;

/* INIT */
int							init(t_manager *manager, int argc, char **argv);

/* PHILO */
int							create_philos(t_manager *manager);
int							join_philos(t_manager *manager);

/* ACTION */
void						print_action(t_philo *philo, char *action_msg);
void						isFork(t_philo *philo);
void						eating(t_philo *philo);
void						sleeping(t_philo *philo);
void						thinking(t_philo *philo);

/* MONITOR */
void						monitor(t_manager *manager);

/* UTIL */
int							ft_atoi(const char *arr);
long long					get_ms_time(void);
size_t						ft_strlen(const char *s);

/* ERROR */
int							pthread_error(t_manager *manager, int thread_cnt);
int							throw_error(char *msg);

#endif
