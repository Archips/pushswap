/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <athirion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 10:33:50 by athirion          #+#    #+#             */
/*   Updated: 2022/04/08 14:46:09 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_lst
{
	struct s_lst	*next;
	int				content;
	int				senpai;
	int				id;
	int				cost;
}	t_lst;

typedef struct s_data
{
	int			*tab;
	size_t		tab_size;
	t_lst		*stack_a;
	t_lst		*stack_b;
	int			size_a;
	int			size_b;
}	t_data;

/*
 ** [ SECURITY.c ]
 */

void	ft_free(void *ptr);
void	ft_free_tab(void **tab);
void	ft_exit(char *msg);
void	ft_error(char **strtab, int *numtab);

/*
 ** [ CHECK_ARGS.C ]
 */

int		ft_duplicate(int *tab, int id, long int num);
int		ft_isnum(char *str);
int		ft_have_num(char *str);

/*
 ** [ PARSE_ARGS.C ]
 */

/* size_t	ft_tablen(char	**tab) */
/* char	**ft_split_numbers(int ac, char **av); */
void	ft_parser(t_data *data, int ac, char **av);

/*
 ** [ LISTUTILS_3.C ]
 */

t_lst	*ft_listmin(t_lst *lst);
t_lst	*ft_listmax(t_lst *lst);
int     ft_listissort(t_lst *lst);

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

/*
 ** [ GET_NEXT_LINE/UTILS.C]
 */

size_t	ft_strlen(const char *s);
int		ft_is_nl(char *str);
size_t		ft_len_newline(char *str);
char	*ft_substr_gnl(char *s, unsigned int start, size_t len);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_get_line(char *temp);
char	*ft_update_temp(char *temp);
char	*get_next_line(int fd);

/*
 ** [ CHECKER.C ]
 */

void	ft_read_operations(t_data *data);

/*
 ** [ SWAP.C ]
 */

void    ft_sa(t_lst **stack_a);
void    ft_sb(t_lst **stack_b);
void    ft_ss(t_lst **stack_a, t_lst **stack_b);

/*
 ** [ PUSH.C ]
 */

void    ft_pa(t_lst **stack_a, t_lst **stack_b);
void    ft_pb(t_lst **stack_a, t_lst **stack_b);

/*
 ** [ ROTATE.C ]
 */

void    ft_ra(t_lst **stack_a);
void    ft_rb(t_lst **stack_b);
void    ft_rr(t_lst **stack_a, t_lst **stack_b);

/*
 ** [ REVERSE.C ]
 */

void    ft_rra(t_lst **stack_a);
void    ft_rrb(t_lst **stack_b);
void    ft_rrr(t_lst **stack_a, t_lst **stack_b);

#endif 
