/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 13:06:39 by pstubbs           #+#    #+#             */
/*   Updated: 2018/07/16 11:00:00 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		singlestackcmd(char *cmd, t_hold *node)
{
	int	ret;

	ret = 0;
	if (ft_strcmp(cmd, "sa") == 0)
		ret = sa(node);
	else if (ft_strcmp(cmd, "ra") == 0)
		ret = ra(node);
	else if (ft_strcmp(cmd, "rra") == 0)
		ret = rra(node);
	else if (ft_strcmp(cmd, "pa") == 0)
		ret = pa(node);
	else if (ft_strcmp(cmd, "sb") == 0)
		ret = sb(node);
	else if (ft_strcmp(cmd, "rb") == 0)
		ret = rb(node);
	else if (ft_strcmp(cmd, "rrb") == 0)
		ret = rrb(node);
	else if (ft_strcmp(cmd, "pb") == 0)
		ret = pb(node);
	return (ret);
}

int		combostackcmd(char *cmd, t_hold *node)
{
	int	ret;

	ret = 0;
	if (ft_strcmp(cmd, "ss") == 0)
		ret = ss(node);
	else if (ft_strcmp(cmd, "rr") == 0)
		ret = rr(node);
	else if (ft_strcmp(cmd, "rrr") == 0)
		ret = rrr(node);
	return (ret);
}

int		commandcheck(char *cmd, t_hold *node)
{
	int	ret;

	ret = 0;
	if ((ret = singlestackcmd(cmd, node)) == 0 )
		ret += combostackcmd(cmd, node);

	return (ret);
}


int		get_commands(t_hold *node)
{
	char	*cmd;
	char	tmp[5];
	int		ret;

	// if (issorted(node) == 1)
	// {
	// 	OK;
	// 	exit(1);
	// }
	ft_bzero(tmp, 5);
	while ((ret = get_next_line(0, &cmd)) != 0)
	{
		
		if (ret != 0)
			ft_strcpy(tmp, cmd);
		// printf("CMD  = %s\n",cmd );
		if (commandcheck(cmd, node) == 0)
		{
			ERROR;
			exit(1);
		}

		debugmode(node);
		if (node->supcolour == 1)
			colouroutput(node, tmp);
	}
	if (issorted(node) == 1)
		{
		OK;
		exit(1);
		}
	colouroutput(node, tmp);
	KO;
	return (1);
}