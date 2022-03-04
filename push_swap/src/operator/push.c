/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 01:48:48 by nkim              #+#    #+#             */
/*   Updated: 2022/02/28 14:52:10 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int push(t_stack *from, t_stack *to)
{
	t_node *target;

	if (!from->head)
		return 0;
	target = from->head;
	from->head = target->next;
	from->len--;
	if (from->head)
		from->head->prev = NULL;
	else
		from->tail = NULL;

	target->next = to->head;
	if (target->next)
		target->next->prev = target;
	to->head = target;
	to->len++;
	if (to->len == 1)
		to->tail = to->head;
	return 1;
}