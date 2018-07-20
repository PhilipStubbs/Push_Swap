/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 14:01:50 by pstubbs           #+#    #+#             */
/*   Updated: 2018/07/20 09:59:13 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# define ERROR ft_putendl_fd("Error", 2);

# define SA ft_putendl_fd("sa", 1);
# define SB ft_putendl_fd("sb", 1);
# define PA ft_putendl_fd("pa", 1);
# define PB ft_putendl_fd("pb", 1);
# define RA ft_putendl_fd("ra", 1);
# define RB ft_putendl_fd("rb", 1);
# define RRA ft_putendl_fd("rra", 1);
# define RRB ft_putendl_fd("rrb", 1);
# define SS ft_putendl_fd("ss", 1);
# define RR ft_putendl_fd("rr", 1);
# define RRR ft_putendl_fd("rrr", 1);

# define NRM  "\x1B[0m"
# define RED  "\x1B[31m"
# define GRN  "\x1B[32m"
# define YEL  "\x1B[33m"
# define BLU  "\x1B[34m"
# define MAG  "\x1B[35m"
# define CYN  "\x1B[36m"
# define WHT  "\x1B[37m"

typedef	struct		s_stack
{
	int				data;
	int				pos;
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
	int				vis;
	int				colour;
	int				supcolour;
}					t_hold;

t_hold				*malloctime(void);
int					searchandmalloc(char **str, t_hold *node, int arc);
int					populatestack(char **str, t_hold *node, int checker);
void				debugmode(t_hold *node);
void				colouroutput(t_hold *node, char *cmd);
t_stack				*startpop(t_stack **list);
t_stack				*endpop(t_stack **list);
int					listsize(t_stack *lst);
int					issorted(t_hold *node);
int					islistsorted(t_stack *list, char ab);
void				visualiser(t_hold *node, char *cmd);

int					sa(t_hold *node, char *cmd, int set);
int					pa(t_hold *node, char *cmd, int set);
int					ra(t_hold *node, char *cmd, int set);
int					rra(t_hold *node, char *cmd, int set);

int					sb(t_hold *node, char *cmd, int set);
int					pb(t_hold *node, char *cmd, int set);
int					rb(t_hold *node, char *cmd, int set);
int					rrb(t_hold *node, char *cmd, int set);

int					ss(t_hold *node, char *cmd, int set);
int					rr(t_hold *node, char *cmd, int set);
int					rrr(t_hold *node, char *cmd, int set);

int					lastlinkval(t_stack *lst);
int					normlize(t_hold *node, int size);
int					newsort(t_hold *node, char *cmd);
int					maxposition(t_stack *lst, int max, int totalrange);
void				dumbsort(t_hold *node, char *cmd);
void				movea(t_hold *node, int totalrange, int size, char *cmd);
void				sortbackin(t_hold *node, char *cmd);
int					maxval(t_stack *lst);
int					closestsmaxval(t_stack *tmp, int totalrange, int hi);
int					maxposition(t_stack *lst, int max, int totalrange);

#endif
