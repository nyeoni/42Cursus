/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 20:10:09 by nkim              #+#    #+#             */
/*   Updated: 2022/05/05 22:24:03 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void monitor(t_manager *manager)
{
	int i;
	long long starve_time;

	while (1) {
		i = 0;
		while (i < manager->number_of_philos)
		{
			pthread_mutex_lock(&manager->philos[i].mutex);
			starve_time = get_ms_time() - manager->philos[i].last_eat_ms_time;
			pthread_mutex_unlock(&manager->philos[i].mutex);

			if (starve_time >= manager->time_to_die)
			{
				pthread_mutex_lock(&manager->print);
				print_action(&manager->philos[i], "\x1B[31mdied\x1B[0m");
				manager->finish = TRUE;
				pthread_mutex_unlock(&manager->print);

				join_philos(manager);
				return;
			}
			i++;
		}
	}
}