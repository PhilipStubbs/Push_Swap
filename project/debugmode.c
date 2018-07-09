/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugmode.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 14:01:14 by pstubbs           #+#    #+#             */
/*   Updated: 2018/07/07 14:01:18 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	output(t_stack *temp)
{
	if (temp != NULL)
	{
		ft_putchar(' ');
		ft_putnbr(temp->data);
	}
	else
	{
		ft_putchar(' ');
		ft_putchar(' ');
	}
}

void	debugmode(t_hold *node)
{
	int i;
	t_stack	*tempa;
	t_stack *tempb;

	if (node->debug != 1)
		return ;
	i = 0;
	tempa = node->a;
	tempb = node->b;
	while (i < node->size)
	{
		if (tempa->next != NULL)
		{
			output(tempa);
			tempa = tempa->next;
		}
		if (tempb != NULL)
		{	
			output(tempb);
			tempb = tempb->next;
		}
		i++;
		ft_putchar('\n');
	}
	ft_putendl("___	___");
	ft_putendl(" a	 b");
}
