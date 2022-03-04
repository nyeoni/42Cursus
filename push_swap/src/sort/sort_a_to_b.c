/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 23:19:31 by nkim              #+#    #+#             */
/*   Updated: 2022/03/04 16:44:48 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_three_or_under_chunk(t_stacks *stacks, int len)
{
	t_stack *stack;

	stack = &stacks->a;
	if (len < 2)
		return ;
	else if (len == 2
		&& stack->head->content > stack->head->next->content)
		operator("sa", stacks);
	if (len == 3 && !is_ascending(stack, 3))
	{
		if (stack->head->content > stack->head->next->content)
			operator("sa", stacks);
		if (!is_ascending(stack, 3))
		{
			operator("ra", stacks);
			operator("sa", stacks);
			operator("rra", stacks);
		}
		if (stack->head->content > stack->head->next->content)
			operator("sa", stacks);
	}
}

void move_a_to_b(t_stacks *stacks, int pivot[2], int cnt[3], int len)
{
	while (len--)
	{
		if (stacks->a.head->content >= pivot[LARGE])
		{
			operator("ra", stacks);
			++cnt[RA_CNT];
		}
		else
		{
			operator("pb", stacks);
			++cnt[PB_CNT];
			if (stacks->b.head->content >= pivot[SMALL])
			{
				if (len && stacks->a.head->content >= pivot[LARGE])
				{
					operator("rr", stacks);
					len--;
					++cnt[RA_CNT];
				}
				else
					operator("rb", stacks);
				++cnt[RB_CNT];
			}
		}
	}
}

static void rotate_back(t_stacks *stacks, int ra_cnt, int rb_cnt)
{
	while (ra_cnt > 0 || rb_cnt > 0)
	{
		if (ra_cnt > 0 && rb_cnt > 0)
			operator("rrr", stacks);
		else if (ra_cnt > 0)
			operator("rra", stacks);
		else if (rb_cnt > 0)
			operator("rrb", stacks);
		ra_cnt--;
		rb_cnt--;
	}
}

void sort_a_to_b(t_stacks *stacks, int len)
{
	int pivot[2];
	int cnt[3];

	if (len <= 3)
		return (sort_three_or_under_chunk(stacks, len));
	ft_memset(cnt, 0, sizeof(cnt));
	select_pivot(pivot, stacks->a, len);
	// print_stacks(stacks);
	move_a_to_b(stacks, pivot, cnt, len);
	// print_stacks(stacks);
	// print_all_node(&stacks->a);
	rotate_back(stacks, cnt[RA_CNT], cnt[RB_CNT]);
	// print_stacks(stacks);
	// print_all_node(&stacks->a);
	sort_a_to_b(stacks, cnt[RA_CNT]);
	// print_stacks(stacks);
	// print_all_node(&stacks->a);
	sort_b_to_a(stacks, cnt[RB_CNT]);
	// print_stacks(stacks);
	// print_all_node(&stacks->a);
	sort_b_to_a(stacks, cnt[PB_CNT] - cnt[RB_CNT]);
	// print_all_node(&stacks->a);

	// print_stacks(stacks);
}