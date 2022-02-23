/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 01:48:48 by nkim              #+#    #+#             */
/*   Updated: 2022/02/24 02:31:28 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push(t_stack *from, t_stack *to)
{
	t_list *target;

	if (!from->head)
		return ;
	target = from->head;
	from->head = target->next;
	from->len--;
	if (from->len < 1)
		from->tail = NULL;
	target->next = to->head;
	to->head = target;
	to->len++;
	if (to->len == 1)
		to->tail = to->head;
}