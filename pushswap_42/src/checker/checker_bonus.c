/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 16:18:36 by athirion          #+#    #+#             */
/*   Updated: 2022/04/13 16:52:40 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

/*
 ** Parse each push_swap output line into its corresponding operation.
 */

static void	ft_get_operations(t_data *data)
{
	ft_printf("#1\n");
	if (ft_strncmp(data->op, "sa\n", 3) == 0)
	{
		ft_printf("#2\n");
		ft_swap(data->stack_a, "sa", data);
		ft_printf("#3\n");
	}
	else if (ft_strncmp(data->op, "sb\n", 3) == 0)
	{
		ft_printf("#4\n");
		ft_swap(data->stack_b, "sb", data);
		ft_printf("#5\n");
	}
	else if (ft_strncmp(data->op, "ss\n", 3) == 0)
	{
		ft_printf("#6\n");
		ft_ss(data);
		ft_printf("#7\n");
	}
	else if (ft_strncmp(data->op, "pa\n", 3) == 0)
	{
		ft_printf("#8\n");
		ft_push(&data->stack_a, &data->stack_b, "pa", data);
		ft_printf("#9\n");
	}
	else if (ft_strncmp(data->op, "pb\n", 3) == 0)
	{
		ft_printf("#10\n");
		ft_push(&data->stack_b, &data->stack_a, "pb", data);
		ft_printf("#11\n");
	}
	else if (ft_strncmp(data->op, "ra\n", 3) == 0)
	{
		ft_printf("#12\n");
		ft_rotate(&data->stack_a, "ra", data);
		ft_printf("#13\n");
	}
	else if (ft_strncmp(data->op, "rb\n", 3) == 0)
	{
		ft_printf("#14\n");
		ft_rotate(&data->stack_b, "rb", data);
		ft_printf("#15\n");
	}
	else if (ft_strncmp(data->op, "rr\n", 3) == 0)
	{
		ft_printf("#16\n");
		ft_rr(data);
		ft_printf("#17\n");
	}
	else if (ft_strncmp(data->op, "rra\n", 4) == 0)
	{
		ft_printf("#18\n");
		ft_reverse_rotate(&data->stack_a, "rra", data);
		ft_printf("#19\n");
	}
	else if (ft_strncmp(data->op, "rrb\n", 4) == 0)
	{
		ft_printf("#20\n");
		ft_reverse_rotate(&data->stack_b, "rrb", data);
		ft_printf("#21\n");
	}
	else if (ft_strncmp(data->op, "rrr\n", 4) == 0)
	{
		ft_printf("#22\n");
		ft_rrr(data);
		ft_printf("#23\n");
	}
	else
	{
		ft_printf("#24\n");
		return (ft_putstr_fd("Error\n", 2), ft_clear_exit(data, EXIT_FAILURE));
		ft_printf("#25\n");
	}
}

/*
 ** Read and execute push_swap operations one by one.
 */

void	ft_read_operations(t_data *data)
{
	while (1)
	{
		data->op = get_next_line(0);
		if (!data->op)
			break ;
		ft_get_operations(data);
		free(data->op);
	}
	if (ft_listissort(data->stack_a) && ft_listsize(data->stack_b) == 0)
	{
		ft_putstr_fd("OK\n", 1);
		ft_clear_exit(data, EXIT_SUCCESS);
	}
	ft_putstr_fd("KO\n", 1);
	ft_clear_exit(data, EXIT_FAILURE);
}
