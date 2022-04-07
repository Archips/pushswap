#include "push_swap.h"

/*
 ** ra, rb
 */

void	ft_rotate(t_lst **stack, char *r, t_op *op)
{
	t_lst	*newhead;
	t_lst	*temp;

	temp = *stack;
	newhead = (*stack)->next;
	while ((*stack)->next)
		*stack = (*stack)->next;
	(*stack)->next = temp;
	temp->next = NULL;
	*stack = newhead;
	if (r && PRINT)
		ft_add_op(r, &op);
}

/*
 ** rr
 */

void	ft_rr(t_lst **stack_a, t_lst **stack_b, t_op *op)
{
	ft_rotate (stack_a, NULL, op);
	ft_rotate (stack_b, NULL, op);
	if (PRINT)
		ft_add_op("rr", &op);
}

/*
 ** rra, rrb
 */

void	ft_reverse_rotate(t_lst **stack, char *rr, t_op *op)
{
	t_lst	*newhead;
	t_lst	*temp;

	temp = *stack;
	while ((*stack)->next->next)
		*stack = (*stack)->next;
	newhead = (*stack)->next;
	(*stack)->next = NULL;
	newhead->next = temp;
	*stack = newhead;
	if (rr && PRINT)
		ft_add_op(rr, &op);
}

/*
 ** rrr
 */

void	ft_rrr(t_lst **stack_a, t_lst **stack_b, t_op *op)
{
	ft_reverse_rotate (stack_a, NULL, op);
	ft_reverse_rotate (stack_b, NULL, op);
	if (PRINT)
		ft_add_op("rrr", &op);
}
