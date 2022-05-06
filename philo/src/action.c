/* ************************************************************************** */
/*                                                                            */
/*
                                              :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:59:08 by nkim              #+#    #+#             */
/*   Updated: 2022/05/06 13:43:46 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_action(t_philo *philo, char *action_msg)
{
	int	finish_flag;

	pthread_mutex_lock(&philo->manager->finish_mutex);
	finish_flag = !philo->manager->finish;
	pthread_mutex_unlock(&philo->manager->finish_mutex);
	if (finish_flag)
	{
		printf("%lld ", get_ms_time() - philo->manager->start_ms_time);
		printf("%d ", philo->id);
		printf("%s\n", action_msg);
	}
}

void	isFork(t_philo *philo)
{
	pthread_mutex_lock(&philo->manager->fork[philo->left]);
	pthread_mutex_lock(&philo->manager->print);
	print_action(philo, "\x1B[32mhas taken a fork\x1B[0m");
	pthread_mutex_unlock(&philo->manager->print);
	pthread_mutex_lock(&philo->manager->fork[philo->right]);
	pthread_mutex_lock(&philo->manager->print);
	print_action(philo, "\x1B[32mhas taken a fork\x1B[0m");
	pthread_mutex_unlock(&philo->manager->print);
}

void	eating(t_philo *philo)
{
	int	finish_flag;

	pthread_mutex_lock(&philo->manager->print);
	print_action(philo, "\x1B[33mis eating\x1B[0m");
	philo->start_eat_ms_time = get_ms_time();
	pthread_mutex_unlock(&philo->manager->print);
	while (get_ms_time() - philo->start_eat_ms_time \
			< philo->manager->time_to_eat)
		usleep(500);
	pthread_mutex_lock(&philo->manager->finish_mutex);
	finish_flag = !philo->manager->finish;
	pthread_mutex_unlock(&philo->manager->finish_mutex);
	if (finish_flag)
	{
		pthread_mutex_lock(&philo->mutex);
		philo->last_eat_ms_time = get_ms_time();
		philo->num_of_eat++;
		pthread_mutex_unlock(&philo->mutex);
	}
	pthread_mutex_unlock(&philo->manager->fork[philo->right]);
	pthread_mutex_unlock(&philo->manager->fork[philo->left]);
}

void	sleeping(t_philo *philo)
{
	pthread_mutex_lock(&philo->manager->print);
	print_action(philo, "\x1B[34mis sleeping\x1B[0m");
	philo->start_sleep_ms_time = get_ms_time();
	pthread_mutex_unlock(&philo->manager->print);
	while (get_ms_time() - philo->start_sleep_ms_time \
			< philo->manager->time_to_sleep)
		usleep(500);
}

void	thinking(t_philo *philo)
{
	pthread_mutex_lock(&philo->manager->print);
	print_action(philo, "\x1B[35mis thinking\x1B[0m");
	pthread_mutex_unlock(&philo->manager->print);
}
