/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listsize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 06:35:05 by pstubbs           #+#    #+#             */
/*   Updated: 2018/07/10 06:35:06 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		listsize(t_stack *lst)
{
	int		count;
	t_stack	*tmp;

	count = 0;
	tmp = lst;
	while (tmp != NULL)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}
