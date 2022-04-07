#include "push_swap.h"

/*
 ** Return the cheapest cost.
 */

static int	ft_cheapest_cost(t_lst *stack)
{
	t_lst	*temp;
	int		cost;

	cost = stack->cost;
	temp = stack;
	while (temp)
	{
		if (temp->cost < cost)
			cost = temp->cost;
		temp = temp->next;
	}
	return (cost);
}

/*
 ** Return the element with the cheapest cost.
 */

static t_lst	*ft_cheapest(t_lst *stack)
{
	t_lst	*temp;
	int		cheapest;

	cheapest = ft_cheapest_cost(stack);
	temp = stack;
	while (temp->cost != cheapest)
		temp = temp->next;
	return (temp);
}

/*
 ** Return the id of the senpai (from stack A) that correspond
 ** to the cheapest content (stack B).
 */

static int	ft_cheapest_senpai_id(t_lst *stack_a, t_lst *stack_b)
{
	t_lst	*temp;
	int		cheapest;

	cheapest = ft_cheapest(stack_b)->senpai;
	temp = stack_a;
	while (temp->content != cheapest)
		temp = temp->next;
	return (temp->id);
}

/*
 ** Move the stack A according to the cheapest senpai position.
 */

static void	ft_move_stack_a(t_data *data)
{
	int	size_a;

	size_a = ft_set_ids(data->stack_a);
	if (ft_cheapest_senpai_id(data->stack_a, data->stack_b) > size_a / 2)
		ft_reverse_rotate(&data->stack_a, "rra", data->oplist);
	else if (ft_cheapest_senpai_id(data->stack_a, data->stack_b) <= size_a / 2)
		ft_rotate(&data->stack_a, "ra", data->oplist);
}

/*
 ** Update each node. Re-compute the cheapest node.
 ** Operate the movements (operations). And repeat.
 **
 ** TODO
 ** (appel les costs en boucle entre 2 assignation)
 **
 ** deplace le cheap et l'envoi dans la stack b (fonction en boucle: on
 ** a les valeurs que l'on veut en haut de a et de b, l'id donne dans
 ** quel sens on rotate, on a les cheapest et senpai correspondant =
 ** condition pour push remplit, si id est > que la stack on monte ou
 ** on descend...)
 */

void	ft_move_cheap(t_data *data)
{
	int	content;
	int	senpai;
	int	id;

	content = ft_cheapest(data->stack_b)->content;
	senpai = ft_cheapest(data->stack_b)->senpai;
	id = ft_cheapest(data->stack_b)->id;
	while (data->stack_b->content != content
		|| data->stack_a->content != senpai)
	{
		if (data->stack_b->content != content)
		{
			if (id > ft_set_ids(data->stack_b) / 2)
				ft_reverse_rotate(&data->stack_b, "rrb", data->oplist);
			else if (id <= ft_set_ids(data->stack_b) / 2)
				ft_rotate(&data->stack_b, "rb", data->oplist);
		}
		if (data->stack_a->content != senpai)
			ft_move_stack_a(data);
		if (data->stack_b->content == content
			&& data->stack_a->content == senpai)
			break ;
	}
	ft_push(&data->stack_a, &data->stack_b, "pa", data->oplist);
}
