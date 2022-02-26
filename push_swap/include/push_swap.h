/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 16:57:23 by nkim              #+#    #+#             */
/*   Updated: 2022/02/26 22:21:47 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/include/libft42.h"

// 나중에 지워줄 것
# include <stdio.h>

#define SMALL 0
#define LARGE 1

#define RA_CNT 0
#define PB_CNT 1
#define RB_CNT 2

#define TRUE 1
#define FALSE 0

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
void init_stacks(t_stacks *stacks, int argc, char **argv);

/* SORT */
void select_pivot(int pivot[2], t_stack stack, int len);
void sort_a_to_b(t_stacks *stacks, int cnt);
void sort_three_or_under(t_stacks *stacks, t_stack *stack, int len);
int is_ascending(t_stack *stack, int len);
int is_descending(t_stack *stack, int len);

/* OPERATOR */
void operator(char *op, t_stacks *stacks);
int swap(t_stack *stack);
int push(t_stack *from, t_stack *to);
int rotate(t_stack *stack);
int reverse_rotate(t_stack *stack);

/* UTILS */
void	throw_error();

/* TEST */
void print_stacks(t_stacks *stacks);
void print_all_node(t_stack *stack);
void test_all_op(t_stacks *stacks);


#endif