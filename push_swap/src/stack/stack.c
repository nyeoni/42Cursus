/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 23:39:50 by nkim              #+#    #+#             */
/*   Updated: 2022/02/23 23:40:11 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stacks(t_stacks *stacks)
{
	t_list *a;
	t_list *b;
	int i;

	a = stacks->a.head;
	b = stacks->b.head;
	i = 0;
	printf("a | ");
	while (i < stacks->a.len)
	{
		printf("%s ", (char *)a->content);
		a = a->next;
		i++;
	}
	printf("\n");
	printf("b | ");
	i = 0;
	while (i < stacks->b.len)
	{
		printf("%s ", (char *)b->content);
		b = b->next;
		i++;
	}
	printf("\n");
}

void init_stacks(t_stacks *stacks, int argc, char **argv)
{
	int i;
	t_list *tmp;

	i = 0;
	stacks->a.head = ft_lstnew(argv[i++]);
	tmp = stacks->a.head;
	while (i < argc - 1)
	{
		tmp->next = ft_lstnew(argv[i]);
		tmp = tmp->next;
		i++;
	}
	tmp->next = NULL;
	stacks->a.tail = tmp;
	stacks->a.len = argc - 1;
	stacks->b.head = NULL;
	stacks->b.tail = NULL;
	stacks->b.len = 0;
}