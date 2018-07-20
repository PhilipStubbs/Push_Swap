/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualiser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 08:22:02 by pstubbs           #+#    #+#             */
/*   Updated: 2018/07/20 10:49:40 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		printb(t_stack *b)
{
	int i;

	ft_putstr(YEL);
	while (b != NULL)
	{
		i = b->pos * 2;
		while (i > 0)
		{
			ft_putchar_fd('-', 2);
			i--;
		}
		ft_putchar_fd('\n', 2);
		b = b->next;
	}
}

void		printa(t_stack *a)
{
	int		i;

	ft_putstr(GRN);
	while (a != NULL)
	{
		i = a->pos * 2;
		while (i > 0)
		{
			ft_putchar_fd('-', 2);
			i--;
		}
		ft_putchar_fd('\n', 2);
		a = a->next;
	}
}

void		visualiser(t_hold *node, char *cmd)
{
	t_stack *a;
	t_stack *b;

	a = node->a;
	b = node->b;
	(void)cmd;
	printa(a);
	printb(b);
	ft_putstr(NRM);
}
