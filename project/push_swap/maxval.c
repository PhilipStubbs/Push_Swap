/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maxval.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 09:53:37 by pstubbs           #+#    #+#             */
/*   Updated: 2018/07/20 09:54:05 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
