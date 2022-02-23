/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 01:47:12 by nkim              #+#    #+#             */
/*   Updated: 2022/02/24 02:23:55 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(t_stack *stack)
{
	t_list *a;
	t_list *b;

	if (stack->len < 2)
		return ;
	else if (stack->len == 2)
		stack->tail = stack->head;
	a = stack->head;
	b = stack->head->next;
	stack->head = a->next;
	stack->head->next = a;
	stack->head->next->next = b->next;
}