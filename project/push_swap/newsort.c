/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 08:39:01 by pstubbs           #+#    #+#             */
/*   Updated: 2018/07/20 08:45:44 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		maxposition(t_stack *lst, int max, int totalrange)
{
	int		count;
	int		lower;
	t_stack	*a;

	count = 0;
	a = lst;
	lower = max - totalrange;
	if (lower < 0)
		lower = 0;
	while (a != NULL)
	{
		if ((a->pos > lower && a->pos <= max))
		{
			return (count);
		}
		a = a->next;
		count++;
	}
	return (count);
}

int		closestsmaxval(t_stack *tmp, int totalrange, int hi)
{
	int		low;
	t_stack	*a;

	a = tmp;
	low = hi - totalrange;
	if (low < 0)
		low = 0;
	while (a != NULL)
	{
		if ((a->pos > low && a->pos <= hi))
		{
			return (a->data);
		}
		a = a->next;
	}
	return (0);
}

int		maxval(t_stack *lst)
{
	int		hi;
	t_stack	*tmp;

	tmp = lst;
	hi = -2147483648;
	while (tmp != NULL)
	{
		if (tmp->pos > hi)
			hi = tmp->pos;
		tmp = tmp->next;
	}
	return (hi);
}

void	movea(t_hold *node, int totalrange, int size, char *cmd)
{
	int		count;
	int		closestmaxint;
	int		maxpos;
	int		hi;
	t_stack	*tmp;

	count = totalrange;
	tmp = node->a;
	hi = maxval(tmp);
	closestmaxint = closestsmaxval(tmp, totalrange, hi);
	maxpos = maxposition(node->a, closestmaxint, totalrange);
	while (count && tmp != NULL)
	{
		if (node->supcolour == 1)
			colouroutput(node, cmd);
		if (tmp->data == closestmaxint)
		{
			pb(node, cmd, 1);
			count--;
			tmp = node->a;
			closestmaxint = closestsmaxval(tmp, totalrange, hi);
			maxpos = maxposition(node->a, closestmaxint, totalrange);
		}
		else if (maxpos >= size / 2)
			rra(node, cmd, 1);
		else if (maxpos < size / 2)
			ra(node, cmd, 1);
		tmp = node->a;
		if (node->supcolour == 1 || node->vis == 1)
			colouroutput(node, cmd);
		debugmode(node);
	}
}

void	sortbackin(t_hold *node, char *cmd)
{
	t_stack	*b;
	int		maxint;
	int		ctoint;
	int		size;

	b = node->b;
	size = listsize(b);
	maxint = maxval(b);
	ctoint = maxposition(b, maxint, 1);
	while (b != NULL)
	{
		if (b->pos == maxint)
		{
			pa(node, cmd, 1);
			b = node->b;
			size = listsize(b);
			maxint = maxval(b);
			ctoint = maxposition(b, maxint, 1);
		}
		else if (ctoint >= size / 2)
			rrb(node, cmd, 1);
		else if (ctoint < size / 2)
			rb(node, cmd, 1);
		if (node->supcolour == 1 || node->vis == 1)
			colouroutput(node, cmd);
		debugmode(node);
		b = node->b;
	}
}

void	settotalrange(int *totalrange, t_hold *node)
{
	if (*totalrange != 0)
		*totalrange = *totalrange - (*totalrange / 5);
	else
		*totalrange = node->size / 5;
	if (*totalrange < 5)
		*totalrange = 4;
}

int		newsort(t_hold *node)
{
	char	*cmd;
	t_stack	*a;
	int		size;
	int		totalrange;

	cmd = (char*)ft_memalloc(sizeof(char) * 4);
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
