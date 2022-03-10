/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 16:57:10 by nkim              #+#    #+#             */
/*   Updated: 2022/03/10 14:23:12 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	init_stacks(&stacks, argc, ++argv);
	if (stacks.a.len <= 3)
		sort_three_or_under(&stacks, stacks.a.len);
	else if (stacks.a.len == 4)
		sort_four(&stacks);
	else if (stacks.a.len == 5)
		sort_five(&stacks);
	else
		sort_a_to_b(&stacks, stacks.a.len);

	// print_stacks(&stacks);
	free_stacks(&stacks);
	// if (is_ascending(&stacks.a, stacks.a.len))
	// 	printf("OK\n");
	// else
	// 	printf("KO\n");
	// free 하는거랑
	// validate
}
