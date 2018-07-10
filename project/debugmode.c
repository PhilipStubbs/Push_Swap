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

int		output(t_stack *temp)
{
	ft_putchar(' ');
	ft_putnbr(temp->data);
	return (1);
}

void	loop(t_stack *tempa, t_stack *tempb, int isplaced, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (tempa != NULL)
		{
			isplaced = output(tempa);
			tempa = tempa->next;
		}
		if (tempb != NULL)
		{
			ft_putchar('\t');
			isplaced = output(tempb);
			tempb = tempb->next;
		}
		i++;
		if (isplaced == 1)
			ft_putchar('\n');
		isplaced = 0;
	}
	ft_putendl("___	___");
	ft_putendl(" a	 b");
}

void	debugmode(t_hold *node)
{
	t_stack	*tempa;
	t_stack	*tempb;
	int		isplaced;

	if (node->debug != 1)
		return ;
	tempa = node->a;
	tempb = node->b;
	isplaced = 0;
	loop(tempa, tempb, isplaced, node->size);
}
