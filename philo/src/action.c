/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:59:08 by nkim              #+#    #+#             */
/*   Updated: 2022/05/05 18:13:21 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void print_action(t_philo *philo, char *action_msg)
{
	printf("finish: %d\n", philo->manager->finish);
	if (!philo->manager->finish)
	{
		printf("%lld ", get_ms_time() - philo->manager->start_ms_time);
		printf("%d ", philo->id);
		printf("%s\n", action_msg);
	}
}

void isFork(t_philo *philo)
{
	printf("%d : isFork\n", philo->id);
	pthread_mutex_lock(&philo->manager->fork[philo->right]);
	pthread_mutex_lock(&philo->manager->print);
	print_action(philo, "\x1B[32mhas taken a fork\x1B[0m");
	pthread_mutex_unlock(&philo->manager->print);

	pthread_mutex_lock(&philo->manager->fork[philo->left]);
	pthread_mutex_lock(&philo->manager->print);
	print_action(philo, "\x1B[32mhas taken a fork\x1B[0m");
	pthread_mutex_unlock(&philo->manager->print);
}

void eating(t_philo *philo)
{
	printf("%d : eating\n", philo->id);
	pthread_mutex_lock(&philo->manager->print);
	print_action(philo, "\x1B[33mis eating\x1B[0m");
	philo->start_eat_ms_time = get_ms_time();
	pthread_mutex_unlock(&philo->manager->print);

	usleep(philo->manager->time_to_eat * 1000);
	philo->num_of_eat++;
	pthread_mutex_unlock(&philo->manager->fork[philo->right]);
	pthread_mutex_unlock(&philo->manager->fork[philo->left]);
}

void sleeping(t_philo *philo)
{
	printf("%d : sleeping\n", philo->id);
	philo->start_sleep_ms_time = get_ms_time();
	pthread_mutex_lock(&philo->manager->print);
	print_action(philo, "\x1B[34mis sleeping\x1B[0m");
	pthread_mutex_unlock(&philo->manager->print);
	usleep(philo->manager->time_to_sleep * 1000);
}

void thinking(t_philo *philo)
{
	printf("%d : thinking\n", philo->id);
	pthread_mutex_lock(&philo->manager->print);
	print_action(philo, "\x1B[35mis thinking\x1B[0m");
	pthread_mutex_unlock(&philo->manager->print);
}