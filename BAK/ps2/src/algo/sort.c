#include "push_swap.h"

/*
 ** Update each node
 **
 ** Update each node's attributes (id, senpai, cost).
 */

static void	ft_update_nodes(t_data *data)
{
	data->size_a = ft_set_ids(data->stack_a);
	data->size_b = ft_set_ids(data->stack_b);
	ft_set_senpais(data);
	ft_set_cost(data);
}

static int	ft_check_order(t_lst *stack)
{
	if (stack && stack->next && (stack->content < stack->next->content))
		return (1);
	return (0);
}

int	ft_issort(t_lst *stack)
{
	t_lst	*temp_1;
	t_lst	*temp_2;

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

/*
 ** TODO
 ** 1. check si on a encore 2 elem dans la stack a / sinon fait le pre-sort
 ** 2. check si les deux elements en tete de A et de B sont ordonnés / sinon
 **    double_swap. Si 1 des 2 stack n'est pas ordonnee il la swap uniqemnt elle
 ** 3. Tant que B n'est pas vide il update costs, senpai, ids.
 **    Puis effectue les movements necessaires. (check, move, check move…)
 ** 4. Quand B est vide il regarde si le plus petite element de A est dans la
 **    partie inférieure ou supperieure de la stack:
 **     si dans partie inferieure: reverse_rotate successifs,
 **     si dans partie supperieur: rotate successifs.
 */

void	ft_sort(t_data *data)
{
	while (ft_set_ids(data->stack_a) > 2)
		ft_pre_sort(data);
	if (ft_check_order(data->stack_a) == 0
		&& ft_check_order(data->stack_b) == 1)
		ft_ss(data);
	else if (ft_check_order(data->stack_a) == 0)
		ft_swap(data->stack_a, "sa", data);
	else if (ft_check_order(data->stack_b) == 1)
		ft_swap(data->stack_b, "sb", data);
	while (ft_set_ids(data->stack_b))
	{
		ft_update_nodes(data);
		ft_move_cheap(data);
	}
	ft_set_ids(data->stack_a);
	if (ft_listmin(data->stack_a)->id > ft_set_ids(data->stack_a) / 2)
		while (data->stack_a->content != ft_listmin(data->stack_a)->content)
			ft_reverse_rotate(&data->stack_a, "rra", data);
	else if (ft_listmin(data->stack_a)->id <= ft_set_ids(data->stack_a) / 2)
		while (data->stack_a->content != ft_listmin(data->stack_a)->content)
			ft_rotate(&data->stack_a, "ra", data);
}
