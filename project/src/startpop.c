/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   startpop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 10:54:47 by pstubbs           #+#    #+#             */
/*   Updated: 2018/07/13 10:15:49 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack		*startpop(t_stack **list)
{
	t_stack	*ret;

	if (*list == NULL)
		return (NULL);
	ret = (*list);
	(*list) = (*list)->next;
	return (ret);
}
