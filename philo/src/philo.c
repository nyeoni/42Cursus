/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:50:13 by nkim              #+#    #+#             */
/*   Updated: 2022/05/06 13:42:21 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*run_philo(t_philo *philo)
{
	int	finish_flag;

	pthread_mutex_lock(&philo->manager->fork[philo->right]);
	print_action(philo, "\x1B[32mhas taken a fork\x1B[0m");
	pthread_mutex_unlock(&philo->manager->fork[philo->right]);
	usleep(philo->manager->time_to_die * 1000);
	return (NULL);
}

static void	*run_philos(void *argv)
{
	t_philo	*philo;
	int		finish_flag;

	philo = (t_philo *)argv;
	if (philo->manager->number_of_philos == 1)
		return (run_philo(philo));
	if (philo->id % 2 == 0)
		usleep(philo->manager->time_to_eat * 500);
	pthread_mutex_lock(&philo->manager->finish_mutex);
	finish_flag = !philo->manager->finish;
	pthread_mutex_unlock(&philo->manager->finish_mutex);
	while (finish_flag)
	{
		isFork(philo);
		eating(philo);
		sleeping(philo);
		thinking(philo);
		pthread_mutex_lock(&philo->manager->finish_mutex);
		finish_flag = !philo->manager->finish;
		pthread_mutex_unlock(&philo->manager->finish_mutex);
	}
	return (NULL);
}

int	join_philos(t_manager *manager)
{
	int	i;

	i = 0;
	while (i < manager->number_of_philos)
	{
		pthread_mutex_destroy(&manager->fork[i]);
		pthread_join(manager->philos[i].thread, NULL);
		i++;
	}
	pthread_mutex_destroy(&manager->print);
	free(manager->philos);
	free(manager->fork);
	return (SUCCESS_FLAG);
}

int	create_philos(t_manager *manager)
{
	int	i;

	i = 0;
	manager->start_ms_time = get_ms_time();
	while (i < manager->number_of_philos)
	{
		if (pthread_create(&manager->philos[i].thread, \
				NULL, run_philos, (void *)&manager->philos[i]))
			return (pthread_error(manager, i));
		i++;
	}
	return (SUCCESS_FLAG);
}
