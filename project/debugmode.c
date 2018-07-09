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

void	debugmode(t_hold *node)
{
	if (node->debug != 1)
		return ;
	int i;
	t_stack	*tempa;
	t_stack *tempb;

	i = 0;
	tempa = node->a;
	tempb = node->b;
		// printf("%d\n",node->size);
	while (i < node->size)
	{
		if (tempa != NULL)
		{
			ft_putnbr(tempa->loc);
			ft_putstr(":");
			ft_putnbr(tempa->data);
			tempa = tempa->next;
		}
		else
		{
			ft_putchar(' ');
			ft_putchar(' ');
		}
		if (tempb != NULL)
		{
			ft_putnbr(tempb->loc);
			ft_putstr(" : ");
			ft_putnbr(tempb->data);
			tempb = tempb->next;
		}
		else
		{
			ft_putchar(' ');
			ft_putchar(' ');
		}
		ft_putchar('\n');
		i++;
	}



	// while ( i < node->size)
	// {
	// 	if (node->a->stack[i] == 0 && node->a->stack[i + 1] == 0)
	// 		ft_putchar(' ');
	// 	else
	// 		ft_putnbr(node->a->stack[i]);
	// 	ft_putchar('\t');
	// 	if (node->b->stack[i] == 0 && 
	// 		(node->b->stack[i + 1] == 0 || node->b->stack[i - 1] == 0))
	// 		ft_putchar(' ');
	// 	else
	// 		ft_putnbr(node->b->stack[i]);
	// 	ft_putchar('\n');
	// 	if (node->a->stack[i] == 0 && node->a->stack[i + 1] == 0 &&
	// 		(node->b->stack[i + 1] == 0 || node->b->stack[i - 1] == 0))
	// 		break ;
	// 	i++;
	// }
	
	ft_putendl("___	___");
	ft_putendl(" a	 b");
}
