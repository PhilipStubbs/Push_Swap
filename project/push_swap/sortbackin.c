/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortbackin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 09:53:21 by pstubbs           #+#    #+#             */
/*   Updated: 2018/07/20 09:53:22 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sortbackinbody(t_hold *node, char *cmd, int ctoint, int size)
{
	if (ctoint >= size / 2)
		rrb(node, cmd, 1);
	else if (ctoint < size / 2)
		rb(node, cmd, 1);
}

void	sortbackin(t_hold *node, char *cmd)
{
	t_stack	*b;
	int		maxint;
	int		ctoint;
	int		size;

	b = node->b;
	size = listsize(b);
	while (b != NULL)
	{
		maxint = maxval(b);
		ctoint = maxposition(b, maxint, 1);
		if (b->pos == maxint)
		{
			pa(node, cmd, 1);
			b = node->b;
			size = listsize(b);
		}
		else
			sortbackinbody(node, cmd, ctoint, size);
		if (node->supcolour == 1 || node->vis == 1)
			colouroutput(node, cmd);
		debugmode(node);
		b = node->b;
	}
}
