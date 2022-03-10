/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 19:33:45 by nkim              #+#    #+#             */
/*   Updated: 2022/03/10 00:28:26 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	select_pivot(int pivot[2], t_stack stack, int len)
{
	t_node	*tmp1;
	t_node	*tmp2;
	int		cnt;
	int		i;
	int		j;

	tmp1 = stack.head;
	i = -1;
	while (++i < len)
	{
		tmp2 = stack.head;
		cnt = 0;
		j = -1;
		while (++j < len)
		{
			if (tmp1->content > tmp2->content)
				cnt++;
			tmp2 = tmp2->next;
		}
		if (cnt == len / 3)
			pivot[SMALL] = tmp1->content;
		else if (cnt == len / 3 * 2)
			pivot[LARGE] = tmp1->content;
		tmp1 = tmp1->next;
	}
}
