/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 01:48:48 by nkim              #+#    #+#             */
/*   Updated: 2022/02/28 01:48:27 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int reverse_rotate(t_stack *stack)
{
	t_node *tail;

	if (stack->len < 2)
		return 0;
	tail = stack->tail;

	stack->tail = tail->prev;
	if (stack->tail)
		stack->tail->next = NULL;

	tail->next = stack->head;
	stack->head->prev = tail;
	stack->head = tail;
	stack->head->prev = NULL;
	if (stack->len == 2 && stack->tail)
		stack->tail->prev = stack->head;
	return 1;
}