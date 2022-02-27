/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 17:08:08 by nkim              #+#    #+#             */
/*   Updated: 2022/02/27 18:56:05 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void move_b_to_a(t_stacks *stacks, int pivot[2], int cnt[3], int len)
{
	printf("move b to a---\n");
	while (len--)
	{
		print_stacks(stacks);
		if (stacks->b.head->content < pivot[SMALL])
		{
			operator("rb", stacks);
			++cnt[RB_CNT];
		}
		else
		{
			operator("pa", stacks);
			++cnt[PA_CNT];
			if (stacks->a.head->content < pivot[LARGE])
			{
				if (len && stacks->b.head->content < pivot[SMALL])
				{
					operator("rr", stacks);
					len--;
					++cnt[RB_CNT];
				}
				else
					operator("ra", stacks);
				++cnt[RA_CNT];
			}
		}
	}
	print_stacks(stacks);
	printf("RB_CNT: %d\n", cnt[RB_CNT]);
	printf("PA_CNT: %d\n", cnt[PA_CNT]);
	printf("RA_CNT: %d\n", cnt[RA_CNT]);
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

static void push_b_to_a(t_stacks *stacks, int len)
{
	t_stack *stack;

	stack = &stacks->b;
	if (len == 2 && stack->head->content < stack->head->next->content)
		operator("sb", stacks);
	else if (len == 3 && is_ascending(stack, len))
	{
		operator("sb", stacks);
		operator("rrb", stacks);
	}
	else if (len == 3 && !is_descending(stack, len))
	{
		if (stack->head->next->content < stack->head->next->next->content)
			operator("rrb", stacks);
		if (!is_descending(stack, len)
			&& stack->head->next->content > stack->head->next->next->content)
			operator("sb", stacks);
		else if (!is_descending(stack, len))
			operator("rb", stacks);
	}
	while (len--)
		operator("pa", stacks);
}

void sort_b_to_a(t_stacks *stacks, int len)
{
	int pivot[2];
	int cnt[3];

	if (len <= 3)
		return (push_b_to_a(stacks, len));
	ft_memset(cnt, 0, sizeof(cnt));
	select_pivot(pivot, stacks->b, len);
	move_b_to_a(stacks, pivot, cnt, len);
	sort_a_to_b(stacks, cnt[PA_CNT] - cnt[RA_CNT]);
	rotate_back(stacks, cnt[RA_CNT], cnt[RB_CNT]);
	sort_a_to_b(stacks, cnt[RA_CNT]);
	sort_b_to_a(stacks, cnt[RB_CNT]);
}