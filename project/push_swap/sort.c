/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 08:39:01 by pstubbs           #+#    #+#             */
/*   Updated: 2018/07/20 10:23:05 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	settotalrange(int *totalrange, t_hold *node)
{
	if (*totalrange != 0)
		*totalrange = *totalrange - (*totalrange / 5);
	else
		*totalrange = node->size / 5;
	if (*totalrange < 5)
		*totalrange = 4;
}

int		sort(t_hold *node, char *cmd)
{
	t_stack	*a;
	int		size;
	int		totalrange;

	totalrange = 0;
	if (node->size <= 5)
	{
		dumbsort(node, cmd);
		return (1);
	}
	while (1)
	{
		a = node->a;
		if (a == NULL)
			sortbackin(node, cmd);
		if (issorted(node) == 1 && listsize(node->b) == 0)
			break ;
		size = listsize(a);
		settotalrange(&totalrange, node);
		movea(node, totalrange, size, cmd);
	}
	if (node->colour == 1)
		colouroutput(node, cmd);
	return (1);
}
