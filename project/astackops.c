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

void	printnode(int	*ar, int  size)
{
	int	i;

	i = 0;
	while (i <= size)
		printf("%d | ",ar[i++] );
	printf("\n");
}

void	intcpy(int *dest, const int *src, size_t n)
{
	int		*p1;
	int		*p2;
	int 	i;

	i = 0;

	p1 = dest;
	p2 = (int*)src;
	while (i <= (int)n)
	{
		*p1++ = *p2++;
		i++;
	}
}


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
	intcpy(tempb , node->b->stack+1, node->size);			// cpy into tempb with our first num
	// printnode(node->b->stack, node->size);
	intcpy(tempa+1 , node->a->stack, node->size);			// cpy into tempa with out first num
	tempa[0] = node->b->stack[0];							// sets first to b[0]
	intcpy(node->a->stack, tempa, node->size);				// cpy that into node stack
	// printnode(node->b->stack, node->size);
	ft_bzero(tempb, node->size);	
	intcpy(tempb, node->b->stack, node->size); 				// cyps all into tempb
	// printnode(tempb, node->size);
	intcpy(node->b->stack, tempb+1, (node->size-2));		//cpy into stack with out first num
	// printnode(node->b->stack, node->size);
	return(1);
}

int		ra(t_hold *node)
{
	int	temp;

	temp = node->a->stack[0];
	intcpy(node->a->stack, node->a->stack+1, node->size);
	node->a->stack[node->size-1] = temp;
	return (1);
}

int		rra(t_hold *node)
{

	
}

















