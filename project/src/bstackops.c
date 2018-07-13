/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bstackops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 16:56:48 by pstubbs           #+#    #+#             */
/*   Updated: 2018/07/08 16:56:49 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		sb(t_hold *node)
{
	t_stack	*tempb;
	int		tmp;

	tempb = node->b;
	if (tempb == NULL)
		return (1);
	if (tempb->next == NULL)
		return (1);
	tempb = tempb->next;
	tmp = node->b->data;
	node->b->data = tempb->data;
	tempb->data = tmp;
	return (1);
}

int		pb(t_hold *node)
{
	t_stack	*tempa;

	if (node->a == NULL)
	{
		return (1);
	}
	tempa = startpop(&node->a);
	if (tempa == NULL)
		return (1);
	tempa->next = node->b;
	node->b = tempa;
	return (1);
}

int		rb(t_hold *node)
{
	t_stack *temp;
	t_stack *tmplist;

	if (listsize(node->b) <= 1)
		return (1);
	temp = startpop(&node->b);
	temp->next = NULL;
	tmplist = node->b;
	while (tmplist->next != NULL)
		tmplist = tmplist->next;
	tmplist->next = temp;
	return (1);
}

int		rrb(t_hold *node)
{
	t_stack	*tmp;
	t_stack	*lst;

	if (listsize(node->b) <= 1)
		return (1);
	tmp = endpop(&node->b);
	if (tmp == NULL)
		return (1);
	lst = (node->b);
	tmp->next = lst;
	lst = tmp;
	node->b = lst;
	return (1);
}
