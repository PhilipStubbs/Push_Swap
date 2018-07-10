/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endpop.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 07:44:04 by pstubbs           #+#    #+#             */
/*   Updated: 2018/07/10 07:44:05 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack		*endpop(t_stack **list)
{
	int		size;
	t_stack	*tmp;
	t_stack	*lst;

	if (*list == NULL)
		return (NULL);
	size = listsize(*list);
	if (size <= 1)
		return (NULL);
	tmp = (*list);
	lst = (*list);
	while (tmp->next != NULL)
		tmp = tmp->next;
	while (lst->next->next != NULL)
		lst = lst->next;
	if (tmp == NULL)
	{
		ERROR;
		return (NULL);
	}
	lst->next = NULL;
	return (tmp);
}
