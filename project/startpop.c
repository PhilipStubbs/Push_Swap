/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poplink.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 10:54:47 by pstubbs           #+#    #+#             */
/*   Updated: 2018/07/09 10:54:48 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack		*startpop(t_stack **list)
{
	int		size;
	t_stack *ret;

	if (*list == NULL)
		return (NULL);
	size = listsize(*list);
	ret = (*list);
	(*list) = (*list)->next;
	// free(ret);
	return (ret);
}
