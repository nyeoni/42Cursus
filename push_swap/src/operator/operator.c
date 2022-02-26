/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 01:28:05 by nkim              #+#    #+#             */
/*   Updated: 2022/02/25 15:10:48 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void operator(char *op, t_stacks *stacks)
{
	if (!ft_strcmp(op, "sa") && swap(&stacks->a))
		ft_putstr_fd("sa\n", 1);
	else if (!ft_strcmp(op, "sb") && swap(&stacks->b))
		ft_putstr_fd("sb\n", 1);
	else if (!ft_strcmp(op, "ss") && swap(&stacks->a) && swap(&stacks->b))
		ft_putstr_fd("ss\n", 1);
	else if (!ft_strcmp(op, "pb") && push(&stacks->a, &stacks->b))
		ft_putstr_fd("pb\n", 1);
	else if (!ft_strcmp(op, "pa") && push(&stacks->b, &stacks->a))
		ft_putstr_fd("pa\n", 1);
	else if (!ft_strcmp(op, "ra") && rotate(&stacks->a))
		ft_putstr_fd("ra\n", 1);
	else if (!ft_strcmp(op, "rb") && rotate(&stacks->b))
		ft_putstr_fd("rb\n", 1);
	else if (!ft_strcmp(op, "rr") && rotate(&stacks->a) && rotate(&stacks->b))
		ft_putstr_fd("rr\n", 1);
	else if (!ft_strcmp(op, "rra") && reverse_rotate(&stacks->a))
		ft_putstr_fd("rra\n", 1);
	else if (!ft_strcmp(op, "rrb") && reverse_rotate(&stacks->b))
		ft_putstr_fd("rrb\n", 1);
	else if (!ft_strcmp(op, "rrr") && reverse_rotate(&stacks->a)
		&& reverse_rotate(&stacks->b))
		ft_putstr_fd("rrr\n", 1);
}