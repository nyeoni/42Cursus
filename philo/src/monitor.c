/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 20:10:09 by nkim              #+#    #+#             */
/*   Updated: 2022/05/06 00:36:59 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void monitor(t_manager *manager)
{
	int i;
	int num_of_full_philos;
	long long starve_time;

	while (TRUE) {
		i = 0;
		num_of_full_philos = 0;
		while (i < manager->number_of_philos)
		{
			pthread_mutex_lock(&manager->philos[i].mutex);
			starve_time = get_ms_time() - manager->philos[i].last_eat_ms_time;
			pthread_mutex_unlock(&manager->philos[i].mutex);

			if (starve_time >= manager->time_to_die)
			{
				pthread_mutex_lock(&manager->print);
				print_action(&manager->philos[i], "\x1B[31mdied\x1B[0m");
				pthread_mutex_unlock(&manager->print);

				pthread_mutex_lock(&manager->finish_mutex);
				manager->finish = TRUE;
				pthread_mutex_unlock(&manager->finish_mutex);

				join_philos(manager);
				return;
			}
			pthread_mutex_lock(&manager->philos[i].mutex);
			if (manager->num_of_time_must_eat != -1 \
				&& manager->philos[i].num_of_eat >= manager->num_of_time_must_eat)
				num_of_full_philos++;
			pthread_mutex_unlock(&manager->philos[i].mutex);
			i++;
		}
		if (num_of_full_philos == manager->number_of_philos)
		{
			// printf("??");
			pthread_mutex_lock(&manager->print);
			pthread_mutex_lock(&manager->finish_mutex);
			manager->finish = TRUE;
			pthread_mutex_unlock(&manager->print);
			pthread_mutex_unlock(&manager->finish_mutex);

			join_philos(manager);
			return;
		}
	}
}