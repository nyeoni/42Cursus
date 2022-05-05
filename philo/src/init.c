/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 18:48:55 by nkim              #+#    #+#             */
/*   Updated: 2022/05/05 14:47:01 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void init_manager(t_manager *manager, int argc, char **argv)
{
	manager->number_of_philos = ft_atoi(argv[1]);
	manager->time_to_die = ft_atoi(argv[2]);
	manager->time_to_eat = ft_atoi(argv[3]);
	manager->time_to_sleep = ft_atoi(argv[4]);
	manager->finish = FALSE;
	if (argc == 6)
		manager->num_of_time_must_eat = ft_atoi(argv[5]);
	manager->start_ms_time = get_ms_time();
}

int init_philos(t_manager *manager)
{
	int i;

	manager->philos = (t_philo *)malloc(sizeof(t_philo) * manager->number_of_philos);
	if (!manager->philos)
		return throw_error("Error: malloc failed");
	i = 0;
	while (i < manager->number_of_philos)
	{
		manager->philos[i].id = i + 1;
		manager->philos[i].right = manager->philos[i].id + 1;
		manager->philos[i].left = manager->philos[i].id - 1;
		manager->philos[i].start_eat_ms_time = get_ms_time();
		manager->philos[i].start_sleep_ms_time = get_ms_time();
		manager->philos[i].manager = manager;
		i++;
	}
	manager->philos[0].left = manager->number_of_philos;
	manager->philos[manager->number_of_philos - 1].right = 1;
	return (SUCCESS_FLAG);
}

int valid_manager(t_manager *manager, int argc)
{
	if (manager->number_of_philos <= 0)
		return throw_error("Number of philosophers must be greater than 0");
	if (manager->time_to_die <= 0)
		return throw_error("Time to die must be greater than 0");
	if (manager->time_to_eat <= 0)
		return throw_error("Time to eat must be greater than 0");
	if (manager->time_to_sleep <= 0)
		return throw_error("Time to sleep must be greater than 0");
	if (argc == 6 && manager->num_of_time_must_eat < 0)
		return throw_error("Number of times to eat must be greater than 0");
	return (SUCCESS_FLAG);
}

int init_mutex(t_manager *manager)
{
	int i;

	manager->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * manager->number_of_philos);
	if (!manager->fork)
		return throw_error("Error: malloc failed");
	if (pthread_mutex_init(&manager->print, NULL))
		return throw_error("pthread_mutex_init failed");
	i = 0;
	while (i < manager->number_of_philos)
	{
		if (pthread_mutex_init(&manager->fork[i], NULL))
			return throw_error("pthread_mutex_init failed");
		i++;
	}
	return SUCCESS_FLAG;
}

int init(t_manager *manager, int argc, char **argv)
{
	init_manager(manager, argc, argv);
	if (valid_manager(manager, argc))
		return (ERROR_FLAG);
	if (init_philos(manager))
		return (ERROR_FLAG);
	if (init_mutex(manager))
		return (ERROR_FLAG);
	return (SUCCESS_FLAG);
}