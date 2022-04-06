#include "push_swap.h"

/*
 ** ra, rb
 */

void	ft_rotate(t_lst **stack, char *r, t_buf *buf)
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
		ft_add_op(r, &buf);
}

/*
 ** rr
 */

void	ft_rr(t_lst **stack_a, t_lst **stack_b, t_buf *buf)
{
	ft_rotate (stack_a, NULL, buf);
	ft_rotate (stack_b, NULL, buf);
	if (PRINT)
		ft_add_op("rr", &buf);
}

/*
 ** rra, rrb
 */

void	ft_reverse_rotate(t_lst **stack, char *rr, t_buf *buf)
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
		ft_add_op(rr, &buf); 
}

/*
 ** rrr
 */

void	ft_rrr(t_lst **stack_a, t_lst **stack_b, t_buf *buf)
{
	ft_reverse_rotate (stack_a, NULL, buf);
	ft_reverse_rotate (stack_b, NULL, buf);
	if (PRINT)
		ft_add_op("rrr", &buf); 
}
