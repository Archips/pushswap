#include "push_swap.h"

/*
 ** Return the id of the smallest element.
 */

static int	ft_id_smallest(t_lst *stack)
{
	ft_printf("FT_ID_SMALLEST\n");
	t_lst	*temp;
	int		id;
	int		content;

	content = stack->content;
	temp = stack;
	while (temp)
	{
		if (temp->content < content)
			id = temp->id;
		temp = temp->next;
	}
	ft_printf("Smallest ID is : [%d]\n", id);
	ft_printf("-----------------------------\n");
	return (id);
}

static void	ft_smallmove(t_data *data)
{
	int	id_smallest;
	int stack_len;
	int	smallest_content;

	ft_printf("FT_SMALLMOVE\n");
	stack_len = ft_set_ids(data->stack_a);
	id_smallest = ft_id_smallest(data->stack_a);
	smallest_content = ft_listmin(data->stack_a)->content;
	ft_printf("Smallest ID is : [%d]\n", id_smallest);
	ft_printf("Stack_len is : [%d]\n", stack_len);
	ft_printf("Smallest_content is : [%d]\n", smallest_content);
	if (id_smallest > stack_len / 2)
	{
		while (data->stack_a->content != smallest_content) // TODO listmin
			ft_reverse_rotate(&data->stack_a, "rra", data->oplist);
	}
	else if (id_smallest <= stack_len / 2)
	{
		while (data->stack_a->content != smallest_content) // TODO listmin
			ft_rotate(&data->stack_a, "ra", data->oplist);
	}
	ft_push(&data->stack_b, &data->stack_a, "pb", data->oplist);
}

static void	ft_smallsort_1(t_data *data)
{
	int	id;

	id = ft_id_smallest(data->stack_a);
	if (id == 2)
	{
		if ((data->stack_a->content > data->stack_a->next->content))
			ft_swap(data->stack_a, "sa", data->oplist);
		ft_reverse_rotate(&data->stack_a, "rra", data->oplist);
	}
	else if (id == 0)
	{
		ft_swap(data->stack_a, "sa", data->oplist);
		ft_rotate(&data->stack_a, "ra", data->oplist);
	}
	else if (id == 1)
	{
		if (data->stack_a->content > data->stack_a->next->next->content)
			ft_rotate(&data->stack_a, "ra", data->oplist);
		else
			ft_swap(data->stack_a, "sa", data->oplist);
	}
}

static void	ft_smallsort_2(t_data *data)
{
	int	id;

	id = ft_set_ids(data->stack_a);
	if (id == 4)
	{
		ft_smallmove(data);
		ft_smallsort_1(data);
		ft_push(&data->stack_a, &data->stack_b, "pa", data->oplist);
	}
	else if (id == 5)
	{
		ft_smallmove(data);
		ft_smallmove(data);
		ft_smallsort_1(data);
		ft_push(&data->stack_a, &data->stack_b, "pa", data->oplist);
		ft_push(&data->stack_a, &data->stack_b, "pa", data->oplist);
	}
}

void	ft_smallsort(t_data *data)
{
	if (ft_set_ids(data->stack_a) == 3)
		ft_smallsort_1(data);
	if (ft_set_ids(data->stack_a) == 4)
		ft_smallsort_2(data);
	if (ft_set_ids(data->stack_a) == 5)
		ft_smallsort_2(data);
}
