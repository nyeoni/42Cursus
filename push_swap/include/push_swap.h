/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 16:57:23 by nkim              #+#    #+#             */
/*   Updated: 2022/02/24 21:22:59 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/include/libft42.h"

// 나중에 지워줄 것
# include <stdio.h>

typedef struct s_list t_list;

typedef struct s_node
{
	int content;
	struct s_node *prev;
	struct s_node *next;
}	t_node;

typedef struct s_stack {
	t_node *head;
	t_node *tail;
	int len;
}	t_stack;

typedef struct s_stacks {
	t_stack a;
	t_stack b;
}	t_stacks;

/* STACK */
void print_stacks(t_stacks *stacks);
void init_stacks(t_stacks *stacks, int argc, char **argv);

/* SORT */
void sort_a_to_b(t_stacks *stacks);

/* OPERATOR */
void swap(t_stack *stack);
void push(t_stack *from, t_stack *to);
void rotate(t_stack *stack);
void reverse_rotate(t_stack *stack);

/* UTILS */
void	throw_error();

#endif