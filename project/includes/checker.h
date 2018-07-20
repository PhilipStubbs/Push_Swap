/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstubbs <pstubbs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 12:39:23 by pstubbs           #+#    #+#             */
/*   Updated: 2018/07/20 10:00:35 by pstubbs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"

# define OK ft_putendl_fd("OK", 2);
# define KO ft_putendl_fd("KO", 2);

int		get_commands(t_hold *node);

#endif
