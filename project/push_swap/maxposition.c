/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maxposition.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 09:52:58 by pstubbs           #+#    #+#             */
/*   Updated: 2018/07/20 09:52:59 by pstubbs          ###   ########.fr       */
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
