/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 22:39:26 by nkim              #+#    #+#             */
/*   Updated: 2022/02/26 23:45:25 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void test_all_op(t_stacks *stacks)
{
	swap(&stacks->a);
	printf("sa");
	print_stacks(stacks);
	print_all_node(&stacks->a);
	print_all_node(&stacks->b);

	push(&stacks->a, &stacks->b);
	printf("pb");
	print_stacks(stacks);
	print_all_node(&stacks->a);
	print_all_node(&stacks->b);

	push(&stacks->b, &stacks->a);
	printf("pa");
	print_stacks(stacks);
	print_all_node(&stacks->a);
	print_all_node(&stacks->b);

	rotate(&stacks->a);
	print_stacks(stacks);
	print_all_node(&stacks->a);
	print_all_node(&stacks->b);

	reverse_rotate(&stacks->a);
	print_stacks(stacks);
	print_all_node(&stacks->a);
	print_all_node(&stacks->b);
}