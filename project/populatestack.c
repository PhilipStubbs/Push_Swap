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

int		createalist(char **str, t_hold *node)
{
	int	i;
	int	size;
	t_stack	*ret;

	i = 0;
	size = 0;
	ret = node->a;
	while (str[size])
		size++;
	while (i < size - 1)
	{
		// printf("%d\n", size);
		ret->next = (t_stack*)malloc(sizeof(t_stack));
		ret = ret->next;
		ret->data = 0;
		ret->loc = 0;
		i++;
		// write(1, "x", 1);
	}
	ret->next = NULL;
	node->b = NULL;
	return (1);
}

int		doublecheck(t_hold *node)
{
	t_stack	*temp;
	t_stack *list;
	
	temp = node->a;
	while(temp->next != NULL)
	{
		list = temp;
		list = list->next;
		while (list->next != NULL)
		{
			if (list->data == temp->data)
			{
				ERROR;
				return (0);
			}
			list = list->next;
		}
		temp = temp->next;
	}
	return (1);
}

int		populatestack(char **str, t_hold *node)
{
	int	i;
	int	dx;
	t_stack	*ret;

	createalist(str, node);
	ret = node->a;
	i = 0;
	while (str[i])
	{
		dx = 0;
		while (ft_isspace(str[i][dx]) == 1)
			dx++;
		if (!(str[i][dx] == '-' && str[i][dx + 1] == 'v') &&
			!(str[i][dx] == '-' && str[i][dx + 1] == 'c'))
		{
			ret->data = atoi(str[i]);
			ret = ret->next;
			if (ret == NULL)
				return (1);
		}
		i++;
	}
	ret->next = NULL;
	return (doublecheck(node));
}
