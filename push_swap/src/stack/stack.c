/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 23:39:50 by nkim              #+#    #+#             */
/*   Updated: 2022/02/24 22:12:42 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_node *create_node(char *arg)
{
	long long content;
	t_node *node;

	content = ft_atoi(arg);
	if (content > 2147483647 || content < -2147483648)
		throw_error();
	node = (t_node *)malloc(sizeof(t_node));
	node->content = (int)content;

	return (node);
}

void init_stacks(t_stacks *stacks, int argc, char **argv)
{
	int i;
	t_node *tmp;

	i = 0;
	stacks->a.head = create_node(argv[i++]);
	tmp = stacks->a.head;
	tmp->prev = NULL;
	while (i < argc - 1)
	{
		tmp->next = create_node(argv[i]);
		tmp->next->prev = tmp;
		tmp = tmp->next;
		i++;
	}
	tmp->next = NULL;
	stacks->a.tail = tmp;
	stacks->a.len = argc - 1;

	ft_memset(&stacks->b, 0, sizeof(t_stack));
}