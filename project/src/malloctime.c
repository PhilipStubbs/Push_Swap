/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloctime.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 14:01:39 by pstubbs           #+#    #+#             */
/*   Updated: 2018/07/20 07:50:12 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_hold	*malloctime(void)
{
	t_hold	*ret;

	ret = (t_hold*)malloc(sizeof(t_hold));
	ret->loc = 0;
	ret->size = 0;
	ret->debug = 0;
	ret->colour = 0;
	ret->supcolour = 0;
	ret->vis = 0;
	ret->a = (t_stack*)malloc(sizeof(t_stack));
	ret->b = (t_stack*)malloc(sizeof(t_stack));
	ret->a->data = 0;
	ret->a->pos = 0;
	ret->b->data = 0;
	ret->b->pos = 0;
	return (ret);
}
