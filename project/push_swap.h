/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 14:01:50 by pstubbs           #+#    #+#             */
/*   Updated: 2018/07/07 14:01:52 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PUSH_SWAP_h
# define PUSH_SWAP_h
# define ERROR ft_putendl_fd("Error", 2);
# include "../libft/libft.h"

#include <stdio.h>

typedef	struct		s_stack
{
	int				data;
	int				loc;
	struct s_stack	*next;
}					t_stack;

typedef	struct		s_pushswap
{
	t_stack			*a;
	t_stack			*b;
	char			**raw;
	int				loc;
	int				size;
	int				debug;
	int				colour;
}					t_hold;

t_hold				*malloctime(void);
int					searchandmalloc(char **str, t_hold *node, int arc);
int					populatestack(char **str, t_hold *node);
void				debugmode(t_hold *node);
t_stack				*popstart(t_stack **list);

int					sa(t_hold *node);
int					pa(t_hold *node);
// int					ra(t_hold *node);
// int					rra(t_hold *node);

int					sb(t_hold *node);
int					pb(t_hold *node);
// int					rb(t_hold *node);
// int					rrb(t_hold *node);


#endif
