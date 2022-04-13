#include "checker.h"

static void	ft_get_operations(t_data *data, char *op)
{
	if (ft_strncmp(op, "sa\n", 3) == 0)
		ft_sa(&data->stack_a);
	else if (ft_strncmp(op, "sb\n", 3) == 0)
		ft_sb(&data->stack_b);
	else if (ft_strncmp(op, "ss\n", 3) == 0)
		ft_ss(&data->stack_a, &data->stack_b);
	else if (ft_strncmp(op, "pa\n", 3) == 0)
		ft_pa(&data->stack_a, &data->stack_b);
	else if (ft_strncmp(op, "pb\n", 3) == 0)
		ft_pb(&data->stack_a, &data->stack_b);
	else if (ft_strncmp(op, "ra\n", 3) == 0)
		ft_ra(&data->stack_a);
	else if (ft_strncmp(op, "rb\n", 3) == 0)
		ft_rb(&data->stack_b);
	else if (ft_strncmp(op, "rr\n", 3) == 0)
		ft_rr(&data->stack_a, &data->stack_b);
	else if (ft_strncmp(op, "rra\n", 4) == 0)
		ft_rra(&data->stack_a);
	else if (ft_strncmp(op, "rrb\n", 4) == 0)
		ft_rrb(&data->stack_b);
	else if (ft_strncmp(op, "rrr\n", 4) == 0)
		ft_rrr(&data->stack_a, &data->stack_b);
	else
		return(ft_putstr_fd("Error\n", 2), exit(EXIT_FAILURE)); //TO DO
}

void	ft_read_operations(t_data *data)
{
	char *op;

	while (1)
	{
		op = get_next_line(0);
		if (!op)
			break;
		ft_get_operations(data, op);
		free(op);
	}
	if (ft_listissort(data->stack_a) && ft_listsize(data->stack_b) == 0)
	{
		ft_putstr_fd("OK\n", 1);
		exit(EXIT_SUCCESS);
	}
	ft_putstr_fd("KO\n", 1);
	exit(EXIT_FAILURE);
}
