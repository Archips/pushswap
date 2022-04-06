#include "push_swap.h"

/*
 ** sa, sb
 */

void	ft_swap(t_lst *stack, char *s, t_buf *buf)
{
	int	temp;

	if (!stack || !stack->next)
		return ;
	temp = stack->content;
	stack->content = stack->next->content;
	stack->next->content = temp;
	if (s && PRINT)
		ft_add_op(s, &buf);
}

/*
 ** ss
 */

void	ft_ss(t_lst *stack_a, t_lst *stack_b, t_buf *buf)
{
	ft_swap (stack_a, NULL, buf);
	ft_swap (stack_b, NULL, buf);
	if (PRINT)
		ft_add_op("ss", &buf);
}

/*
 ** pa, pb
 */

void	ft_push(t_lst **stack_bot, t_lst **stack_top, char *p, t_buf *buf)
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
		ft_add_op(p, &buf);
}
