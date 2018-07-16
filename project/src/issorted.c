/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   issorted.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 14:26:56 by pstubbs           #+#    #+#             */
/*   Updated: 2018/07/16 10:49:19 by pstubbs          ###   ########.fr       */
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
			{	
				return (0);
			}
			tmp = tmp->next;
		}
	}
	if (ab == 'b')
	{
	tmp = list;
		while (tmp->next != NULL)
		{
			if (tmp->data < tmp->next->data)
			{	
				return (0);
			}
			tmp = tmp->next;
		}
	}
	return (1);
}


int		issorted(t_hold *node)
{
	t_stack	*tmpa;
	// t_stack	*tmpb;
	int 	bsize;
	int		asize;

	asize = listsize(node->a);
	bsize = listsize(node->b);
	tmpa = node->a;
	// tmpb = node->b;
	// printf("%d\n",bsize );
	if (asize > 0)
	{
		while (tmpa->next != NULL)
		{
			// printf("%d \n",tmpa->data);
			if (tmpa->data > tmpa->next->data)
			{	
				// if (tmpa->next == NULL && bsize == 0)
				// 	return (0);
				// ft_putendl_fd("isNOTsorted", 2);
				return (0);
			}
			tmpa = tmpa->next;
		}
	}
	if (bsize == 0)
			return (1);
	return (0);
}