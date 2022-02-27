/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_some.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 17:12:16 by nkim              #+#    #+#             */
/*   Updated: 2022/02/27 18:57:55 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* This all methods are for a stack to sort */

static void sort_ordered(t_stacks *stacks, int len)
{
	t_stack *stack;

	stack = &stacks->a;
	if (is_ascending(stack, len))
		return ;
	else if (is_descending(stack, len) && len == 3)
	{
		operator("sa", stacks);
		operator("rra", stacks);
	}
}

/* sort_three: to sort top 3 contents */
void sort_three(t_stacks *stacks)
{
	t_stack *stack;

	stack = &stacks->a;
	if (is_ascending(&stacks->a, 3) || is_descending(stack, 3))
		return sort_ordered(stacks, 3);
	if (stack->head->next->content > stack->head->next->next->content)
		operator("rra", stacks);
	if (!is_ascending(&stacks->a, 3)
		&& stack->head->content < stack->head->next->next->content)
		operator("sa", stacks);
	else if (!is_ascending(stack, 3))
		operator("ra", stacks);
}

/* sort_some: to sort top 1~3 contents */
void sort_three_or_under(t_stacks *stacks, int len)
{
	t_stack *stack;

	stack = &stacks->a;
	if (len != 2)
		return ;
	if (len == 2
		&& stack->head->content > stack->head->next->content)
		operator("sa", stacks);
	else if (len == 3)
		return sort_three(stacks);
}