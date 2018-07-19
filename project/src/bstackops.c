/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bstackops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 16:56:48 by pstubbs           #+#    #+#             */
/*   Updated: 2018/07/16 08:52:53 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		sb(t_hold *node, char *cmd, int set)
{
	t_stack	*temp;
	t_stack	*tempnext;

	temp = node->b;
	if (temp == NULL)
		return (1);
	if (temp->next == NULL)
		return (1);
	temp = node->b;
	tempnext = temp->next;
	temp->next = tempnext->next;
	tempnext->next = temp;
	node->b = tempnext;
	if (set == 1)
	{
		bzero(cmd, 4);
		ft_strcpy(cmd, "sb");
		SB;
	}
	return (1);
}

int		pb(t_hold *node, char *cmd, int set)
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
	if (set == 1)
	{
		bzero(cmd, 4);
		ft_strcpy(cmd, "pb");
		PB;
	}
	return (1);
}

int		rb(t_hold *node, char *cmd, int set)
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
	if (set == 1)
	{
		bzero(cmd, 4);
		ft_strcpy(cmd, "rb");
		RB;
	}
	return (1);
}

int		rrb(t_hold *node, char *cmd, int set)
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
	if (set == 1)
	{
		bzero(cmd, 4);
		ft_strcpy(cmd, "rrb");
		RRB;
	}
	return (1);
}
