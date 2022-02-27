/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 19:14:12 by nkim              #+#    #+#             */
/*   Updated: 2022/02/26 19:14:28 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_ascending(t_stack *stack, int len)
{
	t_node *tmp;
	int i;

	tmp = stack->head;
	i = 0;
	while (i < len - 1)
	{
		if (tmp->content > tmp->next->content)
			return (FALSE);
		tmp = tmp->next;
		i++;
	}
	return (TRUE);
}

int is_descending(t_stack *stack, int len)
{
	t_node *tmp;
	int i;

	tmp = stack->head;
	i = 0;
	while (i < len - 1)
	{
		if (tmp->content < tmp->next->content)
			return (FALSE);
		tmp = tmp->next;
		i++;
	}
	return (TRUE);
}