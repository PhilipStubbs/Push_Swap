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

// static void	printnode(int	*ar, int  size)
// {
// 	int	i;

// 	i = 0;
// 	while (i < size)
// 		printf("%d | ",ar[i++] );
// 	printf("\n");
// }


int		sb(t_hold *node)
{
	int	temp;

	if (node->b->stack[1] == 0)
		return (0);
	temp = node->b->stack[0];
	node->b->stack[0] = node->b->stack[1];
	node->b->stack[1] = temp;
	return (1);
}

int		pb(t_hold *node)
{	
	int	*tempb;
	int	*tempa;

	if (node->a->stack[1] == 0 && node->a->stack[0] == 0)
		return (0);
	tempa = (int*)ft_memalloc(sizeof(char)* node->size);
	tempb = (int*)ft_memalloc(sizeof(char)* node->size);
	ft_bzero(tempa, node->size);
	ft_bzero(tempb, node->size);
	ft_intcpy(tempa , node->a->stack+1, node->size);			// cpy into tempb with our first num
	ft_intcpy(tempb + 1 , node->b->stack, node->size);			// cpy into tempa with out first num
	tempb[0] = node->a->stack[0];							// sets first to b[0]
	ft_intcpy(node->b->stack, tempb, node->size);				// cpy that into node stack
	ft_bzero(tempa, node->size);	
	ft_intcpy(tempa, node->a->stack, node->size); 				// cyps all into tempb
	ft_intcpy(node->a->stack, tempa+1, (node->size-2));		//cpy into stack with out first num
	node->a->stack[node->size - 1] = 0;
	free(tempa);
	free(tempb);
	return(1);
}

int		rb(t_hold *node)
{
	int	temp;

	temp = node->b->stack[0];
	ft_intcpy(node->b->stack, node->b->stack+1, node->size);
	node->b->stack[node->size-1] = temp;
	return (1);
}

int		rrb(t_hold *node)
{
	int	temp;
	int	*tempb;

	temp = node->a->stack[node->size - 1];
	tempb = (int*)ft_memalloc(sizeof(char)* node->size);
	ft_intcpy(tempb, node->b->stack, node->size);
	ft_intcpy(node->b->stack+1, tempb, node->size);
	node->b->stack[0] = temp;
	free(tempb);
	return (1);
}

















