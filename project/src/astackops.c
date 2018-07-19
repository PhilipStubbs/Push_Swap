/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   astackops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 10:51:48 by pstubbs           #+#    #+#             */
/*   Updated: 2018/07/16 11:25:35 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		sa(t_hold *node, char *cmd, int set)
{
	t_stack	*temp;
	t_stack	*tempnext;

	temp = node->a;
	if (temp == NULL)
		return (1);
	if (temp->next == NULL)
		return (1);
	temp = node->a;
	tempnext = temp->next;
	temp->next = tempnext->next;
	tempnext->next = temp;
	node->a = tempnext;
	if (set == 1)
	{
		bzero(cmd, 4);
		ft_strcpy(cmd, "sa");
		SA;
	}
	return (1);
}

int		pa(t_hold *node, char *cmd, int set)
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
	if (set == 1)
	{
		bzero(cmd, 4);
		ft_strcpy(cmd, "pa");
		PA;
	}
	return (1);
}

int		ra(t_hold *node, char *cmd, int set)
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
	if (set == 1)
	{
		bzero(cmd, 4);
		ft_strcpy(cmd, "ra");
		RA;
	}
	return (1);
}

int		rra(t_hold *node, char *cmd, int set)
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
	if (set == 1)
	{
		bzero(cmd, 4);
		ft_strcpy(cmd, "rra");
		RRA;
	}
	return (1);
}
