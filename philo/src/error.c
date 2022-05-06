/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 13:53:06 by nkim              #+#    #+#             */
/*   Updated: 2022/05/06 16:35:48 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	throw_error(char *msg)
{
	write(2, "Error\n", 6);
	write(2, msg, ft_strlen(msg));
	return (1);
}

int	pthread_error(t_manager *manager, int thread_cnt)
{
	int	i;

	i = 0;
	while (i < manager->number_of_philos)
	{
		if (i < thread_cnt)
		{
			pthread_join(manager->philos[i].thread, NULL);
			pthread_mutex_destroy(&manager->philos[i].mutex);
		}
		pthread_mutex_destroy(&manager->fork[i]);
		i++;
	}
	pthread_mutex_destroy(&manager->finish_mutex);
	pthread_mutex_destroy(&manager->print);
	return (ERROR_FLAG);
}
