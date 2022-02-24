/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 01:48:48 by nkim              #+#    #+#             */
/*   Updated: 2022/02/24 21:57:07 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void reverse_rotate(t_stack *stack)
{
	t_node *tail;

	if (stack->len < 2)
		return ;
	tail = stack->tail;
	printf("tail %d\n", stack->tail->content);

	stack->tail = tail->prev;
	printf("tail prev %d\n", stack->tail->content);
	stack->tail->next = NULL;

	tail->next = stack->head;
	stack->head = tail;
	stack->head->prev = NULL;
}