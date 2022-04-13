/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 16:57:10 by nkim              #+#    #+#             */
/*   Updated: 2022/04/13 19:49:20 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	if (argc == 1)
		return (1);
	init_stacks(&stacks, argc, ++argv);
	if (is_ascending(&stacks.a, stacks.a.len))
		return (0);
	if (stacks.a.len <= 3)
		sort_three_or_under(&stacks, stacks.a.len);
	else if (stacks.a.len == 4)
		sort_four(&stacks);
	else if (stacks.a.len == 5)
		sort_five(&stacks);
	else
		sort_a_to_b(&stacks, stacks.a.len);
	free_stacks(&stacks);
}
