/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 12:53:02 by pstubbs           #+#    #+#             */
/*   Updated: 2018/07/20 08:23:58 by pstubbs          ###   ########.fr       */
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
	if (populatestack(node->raw, node, 0) == 0)
		return (0);
	get_commands(node);
	exit(1);
}
