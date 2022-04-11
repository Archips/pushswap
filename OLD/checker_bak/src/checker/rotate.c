/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <athirion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 10:24:52 by athirion          #+#    #+#             */
/*   Updated: 2022/04/04 10:40:36 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_ra(t_lst **stack_a)
{
	t_lst	*newhead;
	t_lst	*temp;

	if (!(*stack_a))
		return ;
	temp = (*stack_a);
	newhead = (*stack_a)->next;
	while ((*stack_a)->next)
		(*stack_a) = (*stack_a)->next;
	(*stack_a)->next = temp;
	temp->next = NULL;
	(*stack_a) = newhead;
}

void	ft_rb(t_lst **stack_b)
{
	t_lst	*newhead;
	t_lst	*temp;

	if (!(*stack_b))
		return ;
	temp = (*stack_b);
	newhead = (*stack_b)->next;
	while ((*stack_b)->next)
		(*stack_b) = (*stack_b)->next;
	(*stack_b)->next = temp;
	temp->next = NULL;
	(*stack_b) = newhead;
}

void	ft_rr(t_lst **stack_a, t_lst **stack_b)
{
	ft_ra(stack_a);
	ft_rb(stack_b);
}
