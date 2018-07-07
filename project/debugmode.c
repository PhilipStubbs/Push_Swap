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

	i = 0;
	while ( i < node->size)
	{
		if (node->a->stack[i] == 0 && node->a->stack[i + 1] == 0)
			ft_putchar(' ');
		else
			ft_putnbr(node->a->stack[i]);
		ft_putchar('\t');
		if (node->b->stack[i] == 0 && 
			(node->b->stack[i + 1] == 0 || node->b->stack[i - 1] == 0))
			ft_putchar(' ');
		else
			ft_putnbr(node->b->stack[i]);
		ft_putchar('\n');
		if (node->a->stack[i] == 0 && node->a->stack[i + 1] == 0 &&
			(node->b->stack[i + 1] == 0 || node->b->stack[i - 1] == 0))
			break ;
		i++;
	}
	ft_putendl("_	_");
	ft_putendl("a	b");
}
