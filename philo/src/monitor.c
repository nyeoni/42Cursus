/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 20:10:09 by nkim              #+#    #+#             */
/*   Updated: 2022/05/06 22:22:44 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_full(t_manager *manager)
{
	pthread_mutex_lock(&manager->finish_mutex);
	manager->finish = TRUE;
	pthread_mutex_unlock(&manager->finish_mutex);
	join_philos(manager);
}

static void	philo_died(t_manager *manager, int i)
{
	pthread_mutex_lock(&manager->print);
	print_action(&manager->philos[i], "\x1B[31mdied\x1B[0m");
	pthread_mutex_unlock(&manager->print);
	pthread_mutex_lock(&manager->finish_mutex);
	manager->finish = TRUE;
	pthread_mutex_unlock(&manager->finish_mutex);
	join_philos(manager);
}

long long	get_starve_time(t_manager *manager, int i)
{
	long long	starve_time;
	long long	last_eat_ms_time;

	pthread_mutex_lock(&manager->philos[i].mutex);
	last_eat_ms_time = manager->philos[i].last_eat_ms_time;
	pthread_mutex_unlock(&manager->philos[i].mutex);
	if (!last_eat_ms_time)
		starve_time = get_ms_time() - manager->start_ms_time;
	else
		starve_time = get_ms_time() - last_eat_ms_time;
	return (starve_time);
}

void	monitor(t_manager *manager)
{
	int			i;
	int			num_of_full_philos;
	long long	starve_time;

	while (TRUE)
	{
		i = 0;
		num_of_full_philos = 0;
		while (i < manager->number_of_philos)
		{
			starve_time = get_starve_time(manager, i);
			if (starve_time >= manager->time_to_die)
				return (philo_died(manager, i));
			pthread_mutex_lock(&manager->philos[i].mutex);
			if (manager->num_of_time_must_eat != -1 \
				&& manager->philos[i].num_of_eat \
				>= manager->num_of_time_must_eat)
				num_of_full_philos++;
			pthread_mutex_unlock(&manager->philos[i].mutex);
			i++;
		}
		if (num_of_full_philos == manager->number_of_philos)
			return (philo_full(manager));
	}
}
