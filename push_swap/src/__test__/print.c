/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 22:40:36 by nkim              #+#    #+#             */
/*   Updated: 2022/03/26 14:19:02 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void print_node(t_node *node)
{
	printf("*********node*********\n");
	printf(" content : %d\n", node->content);
	if (node->prev)
		printf(" prev	: %d\n", node->prev->content);
	else
		printf(" prev	: (null)\n");

	if (node->next)
		printf(" next	: %d\n", node->next->content);
	else
		printf(" next	: (null)\n");
	printf("**********************\n");
}

void print_all_node(t_stack *stack)
{
	int i;
	t_node *tmp;

	i = 0;
	tmp = stack->head;
	printf("stack len: %d\n", stack->len);
	while (i < stack->len)
	{
		print_node(tmp);
		tmp = tmp->next;
		i++;
	}
}

void print_stack(t_stack *stack)
{
	t_node *head;
	int i;

	head = stack->head;
	printf("----------------------------\n");

	i = 0;
	printf("a | ");
	while (i < stack->len)
	{
		printf("%s ", ft_itoa(head->content));
		head = head->next;
		i++;
	}
	printf("\n");

	if (stack->len > 0)
	{
		printf("a->head: %d\n", stack->head->content);
		printf("a->tail: %d\n", stack->tail->content);
	}
	else
	{
		printf("a->head: %s\n", "(null)");
		printf("a->tail: %s\n", "(null)");
	}
	printf("a->len: %d\n", stack->len);

	printf("------------------------------\n\n");
}

void print_stacks(t_stacks *stacks)
{
	t_node *a;
	t_node *b;
	int i;

	a = stacks->a.head;
	b = stacks->b.head;
	printf("----------------------------\n");

	i = 0;
	printf("a | ");
	while (i < stacks->a.len)
	{
		printf("%s ", ft_itoa(a->content));
		a = a->next;
		i++;
	}
	printf("\n");
	printf("b | ");
	i = 0;
	while (i < stacks->b.len)
	{
		printf("%d ",  b->content);
		b = b->next;
		i++;
	}
	printf("\n");

	if (stacks->a.len > 0)
	{
		printf("a->head: %d\n", stacks->a.head->content);
		printf("a->tail: %d\n", stacks->a.tail->content);
	}
	else
	{
		printf("a->head: %s\n", "(null)");
		printf("a->tail: %s\n", "(null)");
	}
	printf("a->len: %d\n", stacks->a.len);

	if (stacks->b.len > 0)
	{
		printf("b->head: %d\n", stacks->b.head->content);
		printf("b->tail: %d\n", stacks->b.tail->content);
	}
	else
	{
		printf("b->head: %s\n", "(null)");
		printf("b->tail: %s\n", "(null)");
	}
	printf("b->len: %d\n", stacks->b.len);

	printf("------------------------------\n\n");
}