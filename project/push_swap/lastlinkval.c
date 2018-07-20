/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lastlinkval.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 08:31:38 by pstubbs           #+#    #+#             */
/*   Updated: 2018/07/20 08:31:40 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		lastlinkval(t_stack *lst)
{
	t_stack *tmp;
	int		i;

	i = 0;
	tmp = lst;
	if (tmp == NULL)
		return (0);
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	i = tmp->data;
	return (i);
}
