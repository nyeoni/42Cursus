/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:18:25 by nkim              #+#    #+#             */
/*   Updated: 2022/04/22 17:28:09 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <sys/time.h>

typedef struct s_manager {
	int number_of_philosophers;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
}	t_manager;

void	throw_error(void);
int ft_atoi(const char *arr);

#endif