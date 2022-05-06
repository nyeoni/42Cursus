/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 16:39:10 by nkim              #+#    #+#             */
/*   Updated: 2022/05/06 16:28:46 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	arg_parse(const char *arr)
{
	int	res;
	int	tmp;
	int	sign;
	size_t	i;

	res = 0;
	tmp = 0;
	sign = 1;
	if (*arr == '-')
		return (ERROR_FLAG);
	i = 0;
	while (i < ft_strlen(arr))
	{
		if (*arr >= '0' && *arr <= '9')
			tmp = res * 10 + *arr++ - '0';
		else
			return (ERROR_FLAG);
		if (tmp < res)
			return (ERROR_FLAG);
		res = tmp;
	}
	return (res * sign);
}

long long	get_ms_time(void)
{
	struct timeval	tv;
	long long		ms;

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
