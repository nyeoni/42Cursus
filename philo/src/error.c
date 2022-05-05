/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 13:53:06 by nkim              #+#    #+#             */
/*   Updated: 2022/05/05 14:03:09 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	throw_error(char *msg)
{
	write(2,"\033[31mError\n\033[0m", 6);
	write(2, msg, ft_strlen(msg));
	return (1);
}

int pthread_error(t_manager *manager, int thread_cnt)
{

	return (-1);
}
