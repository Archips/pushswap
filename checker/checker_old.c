/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_old.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <athirion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 16:46:40 by athirion          #+#    #+#             */
/*   Updated: 2022/04/04 13:29:48 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_operation_index(char *op)
{
	int	index;

	index = -1;
	index = 0 * (ft_strncmp(op, "sa", 2) == 0)
		+ 1 * (ft_strncmp(op, "sb", 2) == 0)
		+ 2 * (ft_strncmp(op, "ss", 2) == 0)
		+ 3 * (ft_strncmp(op, "pa", 2) == 0)
		+ 4 * (ft_strncmp(op, "sb", 2) == 0)
		+ 5 * (ft_strncmp(op, "ra", 2) == 0)
		+ 6 * (ft_strncmp(op, "rb", 2) == 0)
		+ 7 * (ft_strncmp(op, "rr", 2) == 0)
		+ 8 * (ft_strncmp(op, "rra", 3) == 0)
		+ 9 * (ft_strncmp(op, "rrb", 3) == 0)
		+ 10 * (ft_strncmp(op, "rrr", 3) == 0);
	if (index == -1)
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
	return (index);
}

void	ft_exit(int success, t_lst *stack_a, t_lst *stack_b)
{
	ft_listclear(&stack_a, free);
	ft_listclear(&stack_b, free);
	if (success)
		exit(EXIT_SUCCESS);
	exit(EXIT_FAILURE);
}

void	ft_ope_tab(void (*ope[11](void *)))
{
	ope[0] = (void *)ft_sa;
	ope[1] = (void *)ft_sb;
	ope[2] = (void *)ft_ss;
	ope[3] = (void *)ft_pa;
	ope[4] = (void *)ft_pb;
	ope[5] = (void *)ft_ra;
	ope[6] = (void *)ft_rb;
	ope[7] = (void *)ft_rr;
	ope[8] = (void *)ft_rra;
	ope[9] = (void *)ft_rrb;
	ope[10] = (void *)ft_rrr;
}

int	ft_stack_len(t_lst *stack)
{
	t_lst	*temp;
	int		len;

	temp = stack;
	len = 0;
	while (temp && temp->next)
	{
		len ++;
		temp = temp->next;
	}
	return (len);
}

int	ft_issort(t_lst *stack)
{
	t_lst *temp_1;
	t_lst *temp_2;

	temp_1 = stack;
	while (temp_1)
	{
		temp_2 = temp_1->next;
		while (temp_2)
		{
			if (temp_1->content > temp_2->content)
				return (0);
			temp_2 = temp_2->next;
		}
		temp_1 = temp_1->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	void	(*ope[11])(void *);
	char	*operation;

	if (av >1)
	{ 
		while (ft_stack_len(stack_b))
		{
			operation = get_next_line(0);
			if (!operation)
			{
				ft_putstr_fd("Error\n", 2);
				exit(EXIT_FAILURE);
			}
			*ope[ft_operation_index(operation)](*stack_a, *stack_b);
			free(operation);
		}
		if (ft_issort(stack_a))
		{
			ft_putstr_fd("OK\n", 1);
			ft_exit(1, stack_a, stack_b);
		}
		ft_putstr_fd("KO\n", 1);
		ft_exit(0, stack_a, stack_b);
	}
	exit(EXIT_SUCCESS);
}
