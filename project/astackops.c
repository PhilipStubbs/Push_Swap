/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   astackops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 10:51:48 by pstubbs           #+#    #+#             */
/*   Updated: 2018/07/08 10:51:49 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		sa(t_hold *node)
{
	t_stack	*tempa;
	int		tmp;

	tempa = node->a;
	if (tempa == NULL)
		return (1);
	// if (tempa->next == NULL)
	// 	return (1);
	tempa = tempa->next;
	tmp = node->a->data;
	node->a->data = tempa->data;
	tempa->data = tmp;
	return (1);
}

int		pa(t_hold *node)
{
	t_stack	*tempb;

	if (node->b == NULL)
	{
		return (1);
	}
	tempb = startpop(&node->b);
	if (tempb == NULL)
		return (1);
	tempb->next = node->a;
	node->a = tempb;
	return (1);
}

int		ra(t_hold *node)
{
	t_stack *temp;
	t_stack *tmplist;

	if (listsize(node->a) <= 1)
		return (1);
	temp = startpop(&node->a);
	temp->next = NULL;
	tmplist = node->a;
	while (tmplist->next != NULL)
		tmplist = tmplist->next;
	tmplist->next = temp;
	return (1);
}

int		rra(t_hold *node)
{
	t_stack	*tmp;
	t_stack	*lst;

	if (listsize(node->a) <= 1)
		return (1);
	tmp = endpop(&node->a);
	if (tmp == NULL)
		return (1);
	lst = (node->a);
	tmp->next = lst;
	lst = tmp;
	node->a = lst;
	return (1);
}
