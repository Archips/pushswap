/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <athirion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 10:15:02 by athirion          #+#    #+#             */
/*   Updated: 2022/04/04 10:42:33 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_sa(t_lst *stack_a, t_lst *stack_b)
{
	int	temp;

	(void) stack_b;
	if (!stack_a || !stack_a->next)
		return ;
	temp = stack_a->content;
	stack_a->content = stack_a->next->content;
	stack_a->next->content = temp;
}

void	ft_sb(t_lst *stack_a, t_lst *stack_b)
{
	int	temp;

	(void) stack_a;
	if (!stack_b || !stack_b->next)
		return ;
	temp = stack_b->content;
	stack_b->content = stack_b->next->content;
	stack_b->next->content = temp;
}

void	ft_ss(t_lst *stack_a, t_lst *stack_b)
{
	ft_sa (stack_a, stack_b);
	ft_sb (stack_a, stack_b);
}
