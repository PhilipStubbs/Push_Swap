/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   issorted.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 14:26:56 by pstubbs           #+#    #+#             */
/*   Updated: 2018/07/20 08:14:21 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		islistsorted(t_stack *list, char ab)
{
	t_stack	*tmp;

	if (ab == 'a')
	{
		tmp = list;
		while (tmp->next != NULL)
		{
			if (tmp->data > tmp->next->data)
				return (0);
			tmp = tmp->next;
		}
	}
	if (ab == 'b')
	{
		tmp = list;
		while (tmp->next != NULL)
		{
			if (tmp->data < tmp->next->data)
				return (0);
			tmp = tmp->next;
		}
	}
	return (1);
}

int		issorted(t_hold *node)
{
	t_stack	*tmpa;
	int		bsize;
	int		asize;

	asize = listsize(node->a);
	bsize = listsize(node->b);
	tmpa = node->a;
	if (asize > 0)
	{
		while (tmpa->next != NULL)
		{
			if (tmpa->data > tmpa->next->data)
				return (0);
			tmpa = tmpa->next;
		}
	}
	if (bsize == 0)
		return (1);
	return (0);
}
