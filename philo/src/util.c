/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 16:39:10 by nkim              #+#    #+#             */
/*   Updated: 2022/05/05 13:53:02 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_atoi(const char *arr) {
	int res;
	int sign;

	res = 0;
	sign = 1;
	if (*arr == '-')
	{
		sign = -1;
		arr++;
	}
	while (*arr >= '0' && *arr <= '9')
		res = res * 10 + *arr++ - '0';
	return (res * sign);
}

long long get_ms_time() {
	struct timeval tv;
	long long ms;

	gettimeofday(&tv, NULL);
	ms = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (ms);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

