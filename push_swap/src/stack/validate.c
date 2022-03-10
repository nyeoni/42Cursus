/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 18:55:45 by nkim              #+#    #+#             */
/*   Updated: 2022/03/10 15:55:46 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	validate_nodes(t_stacks *stacks)
{
	t_node	*tmp1;
	t_node	*tmp2;
	int		i;
	int		j;

	tmp1 = stacks->a.head;
	i = -1;
	while (++i < stacks->a.len)
	{
		tmp2 = stacks->a.head;
		j = -1;
		while (++j < stacks->a.len)
		{
			if (tmp1 != tmp2 && tmp1->content == tmp2->content)
			{
				free_stacks(stacks);
				throw_error();
			}
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
}
