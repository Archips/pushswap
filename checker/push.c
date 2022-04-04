/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <athirion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 10:21:17 by athirion          #+#    #+#             */
/*   Updated: 2022/04/04 10:47:25 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_pa(t_lst *stack_a, t_lst *stack_b)
{
	t_lst	*temp;

	if (!stack_b)
		return ;
	temp = ft_listnew(stack_b->content);
	ft_listadd_front(&stack_a, temp);
	ft_listdelfirst(&stack_b, free);
}

void	ft_pb(t_lst *stack_b, t_lst *stack_a)
{
	t_lst	*temp;

	if (!stack_a)
		return ;
	temp = ft_listnew(stack_a->content);
	ft_listadd_front(&stack_b, temp);
	ft_listdelfirst(&stack_a, free);
}
