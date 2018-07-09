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

int					sa(t_hold *node)
{
	t_stack	*tempa;
	int		tmp;

	tempa = node->a;
	tempa = tempa->next;
	if (tempa->next == NULL)
		return (0);
	tmp = node->a->data;
	node->a->data = tempa->data;
	tempa->data = tmp;
	return (1);
}

int					pa(t_hold *node)
{
	t_stack	*tempb;

	if (node->b == NULL)
	{
		// write(1, "EXIT\n", 5);
		return (0);
	}
	
	tempb = popstart(&node->b);
	tempb->next = node->a;
	node->a = tempb;
	return (1);
}

// sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).

// sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).

// ss : sa and sb at the same time.

// pa : push a - take the first element at the top of b and put it at the top of a. Do
// nothing if b is empty.

// pb : push b - take the first element at the top of a and put it at the top of b. Do
// nothing if a is empty.

// ra : rotate a - shift up all elements of stack a by 1. The first element becomes
// the last one.

// rb : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.

// rr : ra and rb at the same time.

// rra : reverse rotate a - shift down all elements of stack a by 1. The flast element becomes the first one.

// rrb : reverse rotate b - shift down all elements of stack b by 1. The flast element becomes the first one.

// rrr : rra and rrb at the same time.