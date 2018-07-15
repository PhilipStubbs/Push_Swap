/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 14:01:33 by pstubbs           #+#    #+#             */
/*   Updated: 2018/07/13 11:05:22 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int arc, char **arv)
{
	t_hold	*node;

	node = malloctime();

	if (searchandmalloc(arv, node, arc) == 0)
		return (0);
	if(populatestack(node->raw, node, 0) == 0)
		return (0);
	node->size = listsize(node->a);
	normlize(node, node->size);
	sortinhalfs(node);
	// simplerotatesort(node);


	return (1);

}
