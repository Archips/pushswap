/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <athirion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 10:33:50 by athirion          #+#    #+#             */
/*   Updated: 2022/04/04 10:49:22 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

typedef struct s_lst
{
	struct s_lst	*next;
	int				content;
}	t_lst;

/*
 ** [ LISTUTILS_3.C ]
 */

t_lst	*ft_listmin(t_lst *lst);
t_lst	*ft_listmax(t_lst *lst);

/*
 ** [ LISTUTILS_2.C ]
 */

void	ft_listprint_int(t_lst *lst);
void	ft_listdelfirst(t_lst **lst, void (*del)(void *));
void	ft_listdellast(t_lst **lst, void (*del)(void *));
void	ft_listadd_back(t_lst **alst, t_lst *new);
void	ft_listadd_front(t_lst **alst, t_lst *new);

/*
 ** [ LISTUTILS_1.C ]
 */

void	ft_listclear(t_lst **lst, void (*del)(void *));
void	ft_listdelone(t_lst *lst, void (*del)(void *));
t_lst	*ft_listlast(t_lst *lst);
t_lst	*ft_listnew(int content);
int		ft_listsize(t_lst *lst);


void    ft_sa(t_lst *stack_a, t_lst *stack_b);
void    ft_sb(t_lst *stack_a, t_lst *stack_b);
void    ft_ss(t_lst *stack_a, t_lst *stack_b);
void    ft_pa(t_lst *stack_a, t_lst *stack_b);
void    ft_pb(t_lst *stack_a, t_lst *stack_b);
void    ft_ra(t_lst *stack_a, t_lst *stack_b);
void    ft_rb(t_lst *stack_a, t_lst *stack_b);
void    ft_rr(t_lst *stack_a, t_lst *stack_b);
void    ft_rra(t_lst *stack_a, t_lst *stack_b);
void    ft_rrb(t_lst *stack_a, t_lst *stack_b);
void    ft_rrr(t_lst *stack_a, t_lst *stack_b);

#endif 
