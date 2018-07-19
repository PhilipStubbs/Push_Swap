/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 10:59:48 by pstubbs           #+#    #+#             */
/*   Updated: 2018/07/10 10:59:49 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ss(t_hold *node, char *cmd, int set)
{
	sa(node, cmd, set);
	sb(node, cmd, set);
	return (1);
}

int		rr(t_hold *node, char *cmd, int set)
{
	ra(node, cmd, set);
	rb(node, cmd, set);
	return (1);
}

int		rrr(t_hold *node, char *cmd, int set)
{
	rra(node, cmd, set);
	rrb(node, cmd, set);
	return (1);
}
