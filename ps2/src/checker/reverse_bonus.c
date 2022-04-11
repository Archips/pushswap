/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <athirion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 10:29:48 by athirion          #+#    #+#             */
/*   Updated: 2022/04/04 10:41:43 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_rra(t_lst **stack_a)
{
	t_lst	*newhead;
	t_lst	*temp;

	if (!(*stack_a))
		return ;
	temp = (*stack_a);
	while ((*stack_a)->next->next)
		(*stack_a) = (*stack_a)->next;
	newhead = (*stack_a)->next;
	(*stack_a)->next = NULL;
	newhead->next = temp;
	(*stack_a) = newhead;
}

void	ft_rrb(t_lst **stack_b)
{
	t_lst	*newhead;
	t_lst	*temp;

	if (!(*stack_b))
		return ;
	temp = (*stack_b);
	while ((*stack_b)->next->next)
		(*stack_b) = (*stack_b)->next;
	newhead = (*stack_b)->next;
	(*stack_b)->next = NULL;
	newhead->next = temp;
	(*stack_b) = newhead;
}

void	ft_rrr(t_lst **stack_a, t_lst **stack_b)
{
	ft_rra(stack_a);
	ft_rrb(stack_b);
}
