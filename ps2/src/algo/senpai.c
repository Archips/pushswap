#include "push_swap.h"

/*
 ** Find a senpai
 */

static void	ft_senpai(t_data *data, t_lst *stack_b)
{
	t_lst	*tmp;

	stack_b->senpai = ft_listmax(data->stack_a)->content;
	tmp = data->stack_a;
	while (tmp != NULL)
	{
		if (tmp->content < stack_b->senpai)
			if (tmp->content > stack_b->content)
				stack_b->senpai = tmp->content;
		tmp = tmp->next;
	}
}

/*
 ** Set Senpais
 **
 ** Closest value (in terms of value, not distance) between a node in one stack
 ** and a node in the other stack.
 */

void	ft_set_senpais(t_data *data)
{
	t_lst	*temp;

	temp = data->stack_b;
	while (data->stack_b)
	{
		ft_senpai(data, data->stack_b);
		data->stack_b = data->stack_b->next;
	}
	data->stack_b = temp;
}
