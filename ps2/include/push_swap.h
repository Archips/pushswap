#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*
 ** =========[ Defines ]===========
 */

/*
 ** Debug (set to 1 to print errors line and filename)
 */

# ifndef PINFO
#  define PINFO 0
# endif

# ifndef PRINT
#  define PRINT 1
# endif

# define LI __LINE__
# define FI __FILE__

/*
 ** =========[ Includes ]==========
 */

# include <libft.h>

# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

/*
 ** =========[ Structures ]========
 */

typedef struct s_lst
{
	struct s_lst	*next;
	int				content;
	int				id;
	int				senpai;
	int				cost;
}	t_lst;

typedef struct s_buf
{
	struct s_buf	*next;
	char			*op;
}	t_buf;

typedef struct s_data
{
	int			*tab;
	size_t		tab_size;
	t_lst		*stack_a;
	t_lst		*stack_b;
	t_buf		*buf;
	int			size_a;
	int			size_b;
}	t_data;

/*
 ** =========[ Prototypes ]========
 **
 ** Commented = static.
 */

/*
 ** [ PRINT.C ]
 */

void    ft_add_op(char *operation, t_buf **list);

/*
 ** [ SECURITY.C ]
 */

void	ft_free(void *ptr);
void	ft_free_tab(void **tab);
void	ft_exit(char *msg);
void	ft_error(char **strtab, int *numtab);

/*
 ** [ LISTUTILS_3.C ]
 */

int		ft_listissort(t_lst *lst);
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

/*
 ** [ OPERATIONS_2.C ]
 */

void	ft_rotate(t_lst **stack, char *r, t_buf *buf);
void	ft_rr(t_lst **stack_a, t_lst **stack_b, t_buf *buf);
void	ft_reverse_rotate(t_lst **stack, char *rr, t_buf *buf);
void	ft_rrr(t_lst **stack_a, t_lst **stack_b, t_buf *buf);

/*
 ** [ OPERATIONS_1.C ]
 */

void	ft_swap(t_lst *stack, char *s, t_buf *buf);
void	ft_ss(t_lst *stack_a, t_lst *stack_b, t_buf *buf);
void	ft_push(t_lst **stack_bot, t_lst **stack_top, char *p, t_buf *buf);

/*
 ** [ COSTS.C ]
 */

/* static int  ft_dist(int size, int id) */
/* static int  ft_comp(int id_a, int id_b, int size_a, int size_b) */
/* static int  ft_cost(int id_a, int id_b, int size_a, int size_b) */
void	ft_set_cost(t_data *data);

/*
 ** [ SENPAI.C ]
 */

/* static void	ft_senpai(t_data *data, t_lst *stack_b) */
void	ft_set_senpais(t_data *data);

/*
 ** [ ID.C ]
 */

int		ft_set_ids(t_lst *stack);

/*
 ** [ SORT.C ]
 */

/* static void	ft_update_nodes(t_data *data); */
/* static int	ft_check_order(t_lst stack) */
void	ft_sort(t_data *data);

/*
 ** [ MOVES.C ]
 */

/* static int  ft_cheapest_cost(t_lst *stack); */
/* static t_lst    *ft_cheapest(t_lst *stack); */
/* static int  ft_cheapest_senpai_id(t_lst *stack_a, t_lst *stack_b); */
/* static void ft_move_stack_a(t_data *data); */
void	ft_move_cheap(t_data *data);

/*
 ** [ PRE_SORT.C ]
 */

/* static void>ft_sort_tab(int *tab, int size); */
/* static int ft_find_median(int *tab, int size); */
/* static void>ft_update_tab(t_data *data); */
void	ft_pre_sort(t_data *data);

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
 ** [ MAIN.C ]
 */

/* void	ft_init_list_a(t_data *data) */
int		main(int ac, char **av);

#endif
