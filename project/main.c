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
	popstack(node->raw, node, arc);
	// printf("%ihello\n", L'\e[0;34m');

	debugmode(node);
	printf("size:[%d]	debug:[%d]	colour:[%d]\n",node->size, node->debug, node->colour);
	return (1);

}
