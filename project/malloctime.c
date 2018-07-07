/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloctime.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 14:01:39 by pstubbs           #+#    #+#             */
/*   Updated: 2018/07/07 14:01:41 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

t_hold *malloctime(void)
{
	t_hold	*ret;

	ret = (t_hold*)malloc(sizeof(t_hold));
	ret->loc = 0;
	ret->size = 0;
	ret->debug = 0;
	ret->colour = 0;
	ret->a = (t_stack*)ft_memalloc(sizeof(t_stack));
	ret->b = (t_stack*)ft_memalloc(sizeof(t_stack));
	ret->a->stack = (int*)ft_memalloc(sizeof(int));
	ret->a->size = 0;
	ret->a->loc = 0;
	ret->b->stack = (int*)ft_memalloc(sizeof(int));
	ret->b->size = 0;
	ret->b->loc = 0;
	return(ret);
}
