/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:18:06 by nkim              #+#    #+#             */
/*   Updated: 2022/05/05 18:09:21 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
	t_manager manager;
	pthread_t thread;

	if (argc != 5 && argc != 6)
		return throw_error("Wrong number of arguments");
	if (init(&manager, argc, argv))
		return throw_error("Init failed");
	if (create_philos(&manager))
		return throw_error("Philosopher failed");
}