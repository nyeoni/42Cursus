/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 23:39:50 by nkim              #+#    #+#             */
/*   Updated: 2022/03/26 14:27:10 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(char *arg)
{
	long long	content;
	t_node		*node;

	content = array_to_int(arg);
	if (content > 2147483647 || content < -2147483648)
		throw_error();
	node = (t_node *)malloc(sizeof(t_node));
	node->content = (int)content;
	return (node);
}

t_node	*split_argv(char *argv, t_node *tmp, t_stack *stack)
{
	char	**node_arr;

	node_arr = ft_split(argv, ' ');
	while (*node_arr)
	{
		tmp->next = create_node(*node_arr);
		tmp->next->prev = tmp;
		tmp = tmp->next;
		stack->len++;
		node_arr++;
	}
	return (tmp);
}

t_node	*init_head(char *argv, t_stack *stack)
{
	char	*head;
	int		len;
	t_node	*tmp;

	stack->len = 0;
	if (!ft_strchr(argv, ' '))
	{
		stack->head = create_node(argv);
		tmp = stack->head;
		tmp->prev = NULL;
		stack->len++;
	}
	else
	{
		len = ft_strlen(argv) - ft_strlen(ft_strchr(argv, ' '));
		head = (char *)ft_calloc(len + 1, sizeof(char));
		ft_memmove(head, argv, len);
		stack->head = create_node(head);
		tmp = stack->head;
		tmp->prev = NULL;
		stack->len++;
		tmp = split_argv(argv + len, tmp, stack);
		free(head);
	}
	return (tmp);
}

void	free_stacks(t_stacks *stacks)
{
	t_node	*tmp;
	t_node	*target;

	tmp = stacks->a.head;
	while (tmp)
	{
		target = tmp;
		tmp = tmp->next;
		free(target);
	}
}

void	init_stacks(t_stacks *stacks, int argc, char **argv)
{
	int		i;
	t_node	*tmp;

	i = 0;
	tmp = init_head(argv[i++], &stacks->a);
	while (i < argc - 1)
	{
		if (!ft_strchr(argv[i], ' '))
		{
			tmp->next = create_node(argv[i]);
			tmp->next->prev = tmp;
			tmp = tmp->next;
			stacks->a.len++;
		}
		else
			tmp = split_argv(argv[i], tmp, &stacks->a);
		i++;
	}
	tmp->next = NULL;
	stacks->a.tail = tmp;
	ft_memset(&stacks->b, 0, sizeof(t_stack));
	validate_nodes(stacks);
}
