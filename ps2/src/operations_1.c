#include "push_swap.h"

/*
 ** sa, sb
 */

void	ft_swap(t_lst *stack, char *s, t_op *op)
{
	int	temp;

	if (!stack || !stack->next)
		return ;
	temp = stack->content;
	stack->content = stack->next->content;
	stack->next->content = temp;
	if (s && PRINT)
		ft_add_op(s, &op);
}

/*
 ** ss
 */

void	ft_ss(t_lst *stack_a, t_lst *stack_b, t_op *op)
{
	ft_swap (stack_a, NULL, op);
	ft_swap (stack_b, NULL, op);
	if (PRINT)
		ft_add_op("ss", &op);
}

/*
 ** pa, pb
 */

void	ft_push(t_lst **stack_bot, t_lst **stack_top, char *p, t_op *op)
{
	t_lst	*temp;

	if ((*stack_top))
	{
		temp = (*stack_top);
		(*stack_top) = temp->next;
		temp->next = (*stack_bot);
		(*stack_bot) = temp;
	}
	if (p && PRINT)
		ft_add_op(p, &op);
}

/* static void	print_me(t_op *op) */
/* { */
/* 	t_op	*temp; */

/* 	temp = op->next; */
/* 	ft_printf("ლ( `Д’ ლ) -"); */
/* 	while (temp) */
/* 	{ */
/* 		ft_printf(" [ %s ] ->", temp->operation); */
/* 		temp = temp->next; */
/* 	} */
/* 	ft_printf(" NULL (back)\n"); */
/* 	ft_printf("\n"); */
/* } */

/*
 ** TODO comment + protect malloc
 */

void	ft_add_op(char *str, t_op **oplist)
{
	t_op	*new;
	t_op	*temp;

	new = malloc(sizeof(t_op));
	if (!new)
		exit(EXIT_FAILURE);
	new->operation = str;
	new->next = NULL;
	if (!*oplist)
	{
		*oplist = new;
		return ;
	}
	temp = *oplist;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

void	ft_print_op(t_op *op)
{
	t_op	*temp;
	
	temp = op;
	temp = temp->next;
	while (temp && temp->next)
	{
		if (ft_strncmp(temp->operation, "rra", 3) == 0
			&& ft_strncmp(temp->next->operation, "rrb", 3) == 0)
			temp = (ft_printf("rrr\n"), temp->next->next);
		else if (ft_strncmp(temp->operation, "rrb", 3) == 0
			&& ft_strncmp(temp->next->operation, "rra", 3) == 0)
			temp = (ft_printf("rrr\n"), temp->next->next);
		else if (ft_strncmp(temp->operation, "ra", 2) == 0
			&& ft_strncmp(temp->next->operation, "rb", 2) == 0)
			temp = (ft_printf("rr\n"), temp->next->next);
		else if (ft_strncmp(temp->operation, "rb", 2) == 0
			&& ft_strncmp(temp->next->operation, "ra", 2) == 0)
			temp = (ft_printf("rr\n"), temp->next->next);
		else
			temp = (ft_printf("%s\n", temp->operation), temp->next);
	}
}
