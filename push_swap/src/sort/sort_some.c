/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_some.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 17:12:16 by nkim              #+#    #+#             */
/*   Updated: 2022/03/10 00:27:50 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stacks *stacks)
{
	t_stack	*stack;

	stack = &stacks->a;
	if (is_ascending(&stacks->a, 3) || is_descending(stack, 3))
	{
		if (is_ascending(stack, 3))
			return ;
		else if (is_descending(stack, 3))
		{
			operator("sa", stacks);
			operator("rra", stacks);
		}
	}
	if (stack->head->next->content > stack->head->next->next->content)
		operator("rra", stacks);
	if (!is_ascending(&stacks->a, 3) &&
		stack->head->content < stack->head->next->next->content)
		operator("sa", stacks);
	else if (!is_ascending(stack, 3))
		operator("ra", stacks);
}

void	sort_three_or_under(t_stacks *stacks, int len)
{
	t_stack	*stack;

	stack = &stacks->a;
	if (len < 2)
		return ;
	else if (len == 2 && stack->head->content > stack->head->next->content)
		operator("sa", stacks);
	else if (len == 3)
		return (sort_three(stacks));
}

void	sort_four(t_stacks *stacks)
{
	t_node	*tmp;
	int		min;

	tmp = stacks->a.head;
	min = tmp->content;
	while (tmp)
	{
		if (min > tmp->content)
			min = tmp->content;
		tmp = tmp->next;
	}
	while (stacks->a.head->content != min)
		operator("ra", stacks);
	operator("pb", stacks);
	sort_three(stacks);
	operator("pa", stacks);
}

void	get_two_min_node(int min[2], t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->head;
	min[0] = tmp->content;
	min[1] = tmp->next->content;
	tmp = tmp->next->next;
	while (tmp)
	{
		if (tmp->content < min[0] && tmp->content > min[1])
			min[0] = tmp->content;
		else if (tmp->content > min[0] && tmp->content < min[1])
			min[1] = tmp->content;
		else if (tmp->content > min[0] && tmp->content && min[1])
			;
		else if (min[0] > min[1])
			min[0] = tmp->content;
		else
			min[1] = tmp->content;
		tmp = tmp->next;
	}
}

void	sort_five(t_stacks *stacks)
{
	t_stack	*stack;
	int		min[2];
	int		i;

	stack = &stacks->a;
	get_two_min_node(min, stack);
	i = 0;
	while (i < 5)
	{
		if (stack->head->content == min[0] || stack->head->content == min[1])
			operator("pb", stacks);
		else
			operator("ra", stacks);
		i++;
	}
	if (stacks->b.head->content < stacks->b.head->next->content)
		operator("sb", stacks);
	sort_three(stacks);
	operator("pa", stacks);
	operator("pa", stacks);
}
