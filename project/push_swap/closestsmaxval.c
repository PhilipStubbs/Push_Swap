/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closestsmaxval.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 09:51:08 by pstubbs           #+#    #+#             */
/*   Updated: 2018/07/20 09:52:35 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
