/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movea.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 09:53:13 by pstubbs           #+#    #+#             */
/*   Updated: 2018/07/20 09:57:35 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		*setmoveabody(t_hold *node, int totalrange, t_stack *tmp)
{
	int		*sort;

	sort = (int*)ft_memalloc(sizeof(int) * 4);
	sort[0] = totalrange;
	sort[1] = maxval(tmp);
	sort[2] = closestsmaxval(tmp, totalrange, sort[1]);
	sort[3] = maxposition(node->a, sort[2], totalrange);
	return (sort);
}

void	moveabody(t_hold *node, char *cmd, int data, int size)
{
	if (data >= size / 2)
		rra(node, cmd, 1);
	else if (data < size / 2)
		ra(node, cmd, 1);
}

void	movea(t_hold *node, int totalrange, int size, char *cmd)
{
	int		*sort;
	t_stack	*tmp;

	tmp = node->a;
	sort = setmoveabody(node, totalrange, tmp);
	while (sort[0] && tmp != NULL)
	{
		if (node->supcolour == 1)
			colouroutput(node, cmd);
		if (tmp->data == sort[2])
		{
			pb(node, cmd, 1);
			sort[0]--;
			tmp = node->a;
			sort[2] = closestsmaxval(tmp, totalrange, sort[1]);
			sort[3] = maxposition(node->a, sort[2], totalrange);
		}
		else
			moveabody(node, cmd, sort[3], size);
		tmp = node->a;
		if (node->supcolour == 1 || node->vis == 1)
			colouroutput(node, cmd);
		debugmode(node);
	}
}
