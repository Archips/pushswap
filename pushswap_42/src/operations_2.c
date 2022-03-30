#include "push_swap.h"

/*
 ** ra, rb
 */

void	ft_rotate(t_lst **stack, char s)
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
	if (s)
		ft_printf("r%c\n", s);
}

/*
 ** rr
 */

void	ft_rr(t_lst **stack_a, t_lst **stack_b)
{
	ft_rotate (stack_a, '\0');
	ft_rotate (stack_b, '\0');
	ft_printf("rr\n");
}

/*
 ** rra, rrb
 */

void	ft_reverse_rotate(t_lst **stack, char s)
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
	if (s)
		ft_printf("rr%c\n", s);
}

/*
 ** rrr
 */

void	ft_rrr(t_lst **stack_a, t_lst **stack_b)
{
	ft_reverse_rotate (stack_a, '\0');
	ft_reverse_rotate (stack_b, '\0');
	ft_printf("rrr\n");
}
