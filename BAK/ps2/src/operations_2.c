#include "push_swap.h"

/*
 ** ra, rb
 */

void	ft_rotate(t_lst **stack, char *r, t_data *data)
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
		ft_add_op(r, data);
}

/*
 ** rr
 */

void	ft_rr(t_data *data)
{
	ft_rotate(&data->stack_a, NULL, data);
	ft_rotate(&data->stack_b, NULL, data);
	if (PRINT)
		ft_add_op("rr", data);
}

/*
 ** rra, rrb
 */

void	ft_reverse_rotate(t_lst **stack, char *rr, t_data *data)
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
		ft_add_op(rr, data);
}

/*
 ** rrr
 */

void	ft_rrr(t_data *data)
{
	ft_reverse_rotate (&data->stack_a, NULL, data);
	ft_reverse_rotate (&data->stack_b, NULL, data);
	if (PRINT)
		ft_add_op("rrr", data);
}
