/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:18:06 by nkim              #+#    #+#             */
/*   Updated: 2022/04/22 17:34:02 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void init() {}

int main(int argc, char **argv)
{
	t_manager manager;

	if (argc != 4 && argc != 5)
		return (1);

	manager.number_of_philosophers = ft_atoi(argv[1]);
	manager.time_to_die = ft_atoi(argv[2]);
	manager.time_to_eat = ft_atoi(argv[3]);
	manager.time_to_sleep = ft_atoi(argv[4]);

	printf("%d\n",manager.number_of_philosophers);
	printf("%d\n",manager.time_to_die);
	printf("%d\n",manager.time_to_eat);
	printf("%d\n",manager.time_to_sleep);
}