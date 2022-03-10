/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_to_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 15:36:34 by nkim              #+#    #+#             */
/*   Updated: 2022/03/10 16:01:09 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ctoi(char c)
{
	int	res;

	res = c - '0';
	return (res);
}

int	array_to_int(const char *str)
{
	long long	res;
	long long	tmp;
	int			is_minus;
	int			i;

	i = 0;
	is_minus = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			is_minus = -1;
	}
	if (!ft_isdigit(str[i]))
		throw_error();
	res = 0;
	while (i < ft_strlen(str))
	{
		if (!ft_isdigit(str[i]))
			throw_error();
		tmp = res * 10 + ctoi(str[i++]);
		if (tmp < res)
			throw_error();
		res = tmp;
	}
	return ((int)(is_minus * res));
}
