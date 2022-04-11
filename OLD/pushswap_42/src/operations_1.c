#include "push_swap.h"

/*
 ** sa, sb
 */

void	ft_swap(t_lst *stack, char s)
{
	int	temp;

	if (!stack || !stack->next)
		return ;
	temp = stack->content;
	stack->content = stack->next->content;
	stack->next->content = temp;
	if (s)
		ft_printf("s%c\n", s);
}

/*
 ** ss
 */

void	ft_ss(t_lst *stack_a, t_lst *stack_b)
{
	ft_swap (stack_a, '\0');
	ft_swap (stack_b, '\0');
	ft_printf("ss\n");
}

/*
 ** pa, pb
 */

void	ft_push(t_lst **stack_bot, t_lst **stack_top, char p)
{
	t_lst	*temp;

	if (!stack_top)
		return ;
	temp = ft_listnew((*stack_top)->content);
	ft_listadd_front(stack_bot, temp);
	ft_listdelfirst(stack_top, free);
	if (p)
		ft_printf("p%c\n", p);
}
