/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:18:06 by nkim              #+#    #+#             */
/*   Updated: 2022/05/05 14:51:33 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int run_philos(t_manager *manager) {
	int i;

	i = 0;
	manager->start_ms_time = get_ms_time();
	while (i < manager->number_of_philos)
	{
		if (pthread_create(&manager->philos[i].thread, NULL, philo, (void *)&manager->philos[i]))
			return (pthread_error(manager, i));
		i++;
	}
	return (SUCCESS_FLAG);
}

int main(int argc, char **argv)
{
	t_manager manager;

	if (argc != 5 && argc != 6)
		return throw_error("Wrong number of arguments");
	if (init(&manager, argc, argv))
		return throw_error("Init failed");

	// create philosophers
	// int i;
	// i = 0;
	// while(i < manager.number_of_philos) {
	// 	pthread_create(&manager.philos[i].thread, NULL, &philosopher, &manager.philos[i]);
	// 	i++;
	// }
}