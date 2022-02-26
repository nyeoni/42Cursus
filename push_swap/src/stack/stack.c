/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 23:39:50 by nkim              #+#    #+#             */
/*   Updated: 2022/02/24 22:40:13 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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