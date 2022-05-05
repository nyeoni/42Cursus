/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:50:13 by nkim              #+#    #+#             */
/*   Updated: 2022/05/05 18:41:13 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void *run_philo(t_philo *philo)
{
	printf("running philo~\n");
	return SUCCESS_FLAG;
}

static void *run_philos(void *argv)
{
	t_philo *philo;

	printf("running philos~\n");

	philo = (t_philo *)argv;
	if (philo->manager->number_of_philos == 1)
		return (run_philo(philo));
	if (philo->id % 2 == 0)
		usleep(philo->manager->time_to_eat * 1000);

	while (!philo->manager->finish)
	{
		printf("fuckyou\n");
		break;
		// isFork(philo);
		// eating(philo);
		// sleeping(philo);
		// thinking(philo);
	}
	return NULL;
}

int join_philos(t_manager *manager)
{
	int i;

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
	return SUCCESS_FLAG;
}

int create_philos(t_manager *manager)
{
	int i;

	i = 0;
	manager->start_ms_time = get_ms_time();
	while (i < manager->number_of_philos)
	{

		if (pthread_create(&manager->philos[i].thread, NULL, \
				run_philos, (void *)&manager->philos[i]))
			return (pthread_error(manager, i));
		i++;
	}
	join_philos(manager);
	return (SUCCESS_FLAG);
}
