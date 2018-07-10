/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 12:53:02 by pstubbs           #+#    #+#             */
/*   Updated: 2018/07/10 12:53:04 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int arc, char **arv)
{
	t_hold	*node;

	node = malloctime();
	if (arc == 1)
		exit(1);

	if (searchandmalloc(arv, node, arc) == 0)
		return (0);
	if(populatestack(node->raw, node, 1) == 0)
		return (0);
	get_commands(node);

	// issorted(node)

	exit(1);
}