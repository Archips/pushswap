/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <athirion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 10:21:17 by athirion          #+#    #+#             */
/*   Updated: 2022/04/08 15:02:24 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_pa(t_lst **stack_a, t_lst **stack_b)
{
	t_lst	*temp;

	if ((*stack_b))
	{
		temp = (*stack_b);
		(*stack_b) = temp->next;
		temp->next = (*stack_a);
		(*stack_a) = temp;
	}
}

void	ft_pb(t_lst **stack_a, t_lst **stack_b)
{
	t_lst	*temp;

	if ((*stack_a))
	{
		temp = (*stack_a);
		(*stack_a) = temp->next;
		temp->next = (*stack_b);
		(*stack_b) = temp;
	}
}
