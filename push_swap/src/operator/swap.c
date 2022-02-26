/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 01:47:12 by nkim              #+#    #+#             */
/*   Updated: 2022/02/25 01:15:20 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int swap(t_stack *stack)
{
	t_node *a;
	t_node *b;

	if (stack->len < 2)
		return 0;
	else if (stack->len == 2)
		stack->tail = stack->head;
	a = stack->head;
	b = stack->head->next;

	a->next = b->next;
	if (b->next)
		b->next->prev = a;
	a->prev = b;
	b->next = a;
	b->prev = NULL;

	stack->head = b;
	stack->head->next = a;
	return 1;
}