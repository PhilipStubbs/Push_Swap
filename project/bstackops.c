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

int					sb(t_hold *node)
{
	t_stack	*tempb;
	int		tmp;

	tempb = node->b;
	tempb = tempb->next;
	if (tempb->next == NULL)
		return (0);
	tmp = node->b->data;
	node->b->data = tempb->data;
	tempb->data = tmp;
	return (1);
}