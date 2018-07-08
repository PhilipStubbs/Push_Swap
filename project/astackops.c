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

// static void	printnode(int	*ar, int  size)
// {
// 	int	i;

// 	i = 0;
// 	while (i < size)
// 		printf("%d | ",ar[i++] );
// 	printf("\n");
// }

int		sa(t_hold *node)
{
	int	temp;

	if (node->a->stack[1] == 0)
		return (0);
	temp = node->a->stack[0];
	node->a->stack[0] = node->a->stack[1];
	node->a->stack[1] = temp;
	return (1);
}

int		pa(t_hold *node)
{	
	int	*tempb;
	int	*tempa;

	if (node->b->stack[1] == 0 && node->b->stack[0] == 0)
		return (0);
	tempa = (int*)ft_memalloc(sizeof(char)* node->size);
	tempb = (int*)ft_memalloc(sizeof(char)* node->size);
	ft_bzero(tempa, node->size);
	ft_bzero(tempb, node->size);
	ft_intcpy(tempb , node->b->stack+1, node->size);			// cpy into tempb with our first num
	ft_intcpy(tempa + 1 , node->a->stack, node->size);			// cpy into tempa with out first num
	tempa[0] = node->b->stack[0];							// sets first to b[0]
	ft_intcpy(node->a->stack, tempa, node->size);				// cpy that into node stack
	ft_bzero(tempb, node->size);	
	ft_intcpy(tempb, node->b->stack, node->size); 				// cyps all into tempb
	ft_intcpy(node->b->stack, tempb+1, (node->size-2));		//cpy into stack with out first num
	free(tempa);
	free(tempb);
	return(1);
}

int		ra(t_hold *node)
{
	int	temp;

	temp = node->a->stack[0];
	ft_intcpy(node->a->stack, node->a->stack+1, node->size);
	node->a->stack[node->size-1] = temp;
	return (1);
}

int		rra(t_hold *node)
{
	int	temp;
	int	*tempa;

	temp = node->a->stack[node->size - 1];
	tempa = (int*)ft_memalloc(sizeof(char)* node->size);
	ft_intcpy(tempa, node->a->stack, node->size);
	ft_intcpy(node->a->stack+1, tempa, node->size);
	node->a->stack[0] = temp;
	free(tempa);
	return (1);
}

















