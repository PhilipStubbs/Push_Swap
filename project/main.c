/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 14:01:33 by pstubbs           #+#    #+#             */
/*   Updated: 2018/07/07 14:01:34 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int arc, char **arv)
{
	t_hold	*node;

	(void)arc;
	node = malloctime();

	if (searchandmalloc(arv, node, arc) == 0)
		return (0);
	// write(1, "x\n",2);

	if(populatestack(node->raw, node) == 0)
		return (0);

	// write(1, "x\n",2);
	// debugmode(node);
	sa(node);

	ss(node);
	rr(node);
	rrr(node);
	// ss(node);
	// sb(node);
	// pb(node);
	// ra(node);

	// ra(node);
	// ra(node);
	// ra(node);
	// ra(node);
	// ra(node);
	// ra(node);
	// ra(node);
	// ra(node);
	// debugmode(node);
	// rra(node);
	// rra(node);
	// rra(node);
	// rrb(node);

	

	// debugmode(node);

	// 

	// debugmode(node);

	int	count;
	count = listsize(node->a);
	debugmode(node);


	printf("str_size:[%d]	list_size:[%d]	debug:[%d]	colour:[%d]\n",node->size, count, node->debug, node->colour);
	return (1);

}
