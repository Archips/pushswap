/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <athirion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 16:46:40 by athirion          #+#    #+#             */
/*   Updated: 2022/04/03 17:21:40 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

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
	ft_free_list(stack_a, stack_b);
	if (success)
		exit(EXIT_SUCCESS);
	exit(EXIT_FAILURE);
}

void	ft_ope_tab(int (*ope[11](void *)))
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

int	main(int argc, char **argv)
{
	char	*operation;

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
	if (ft_is_sorted(stack_a))
	{
		ft_putstr_fd("OK\n", 1);
		ft_exit(1, stack_a, stack_b);
	}
	ft_putstr_fd("KO\n", 1);
	ft_exit(0, stack_a, stack_b);
}
