/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:50:13 by nkim              #+#    #+#             */
/*   Updated: 2022/05/05 14:50:36 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *philo_one(t_philo *philo)
{
	return SUCCESS_FLAG;
}

void *philo(void *argv)
{
	t_philo *philo;

	philo = (t_philo *)philo;
	if (philo->manager->number_of_philos == 1)
		return (philo_one(philo));
	if (philo->id % 2 == 0)
		usleep(philo->manager->time_to_eat * 1000);
	while (!philo->manager->finish)
	{
		isFork(philo);
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	return NULL;
}