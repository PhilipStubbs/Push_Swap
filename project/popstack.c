/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   popstack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 14:01:45 by pstubbs           #+#    #+#             */
/*   Updated: 2018/07/07 14:01:46 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		popstack(char **str, t_hold *node, int arc)
{
	int	i;
	int	dx;
	int	sti;

	i = 1;
	sti = 0;
	if (arc == 2)
		i = 0;
	while (str[i])
	{
		dx = 0;
		while (ft_isspace(str[i][dx]) == 1)
			dx++;

		if (!(str[i][dx] == '-' && str[i][dx + 1] == 'v') &&
			!(str[i][dx] == '-' && str[i][dx + 1] == 'c'))
		{
			node->a->stack[sti] = ft_atoi(str[i]);
			sti++;
		}
		i++;
	}
	return (i);
}
