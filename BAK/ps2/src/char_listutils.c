#include "push_swap.h"

/*
 ** Delete one list element
 */

void	ft_char_listdelone(t_op *op, void (*del)(void *))
{
	if (!op || !del)
		return ;
	del(op);
}

/*
 ** Delete the first element of a list
 */

void	ft_char_listdelfirst(t_op **op, void (*del)(void *))
{
	t_op	*temp;

	temp = *op;
	if (!temp)
		return ;
	if (!temp->next)
	{
		ft_char_listdelone(temp, del);
		return ;
	}
	*op = (*op)->next;
	ft_char_listdelone(temp, del);
}

/*
 ** Create one list element
 */

t_op	*ft_char_listnew(char *operation, t_data *data)
{
	t_op	*first;

	first = malloc(sizeof(t_op));
	if (!first)
	{
		ft_free(data->tab);
		if (data->stack_a)
			ft_listclear(&data->stack_a, free);
		if (data->stack_b)
			ft_listclear(&data->stack_b, free);
		if (data->oplist)
			ft_char_listclear(&data->oplist, free);
		exit(EXIT_FAILURE);
	}
	first->operation = operation;
	first->next = NULL;
	return (first);
}

/*
 ** Delete a list
 */

void	ft_char_listclear(t_op **op, void (*del)(void *))
{
	t_op	*ptr;

	ptr = *op;
	while (ptr != NULL)
	{
		*op = (*op)->next;
		ft_char_listdelone(ptr, del);
		ptr = *op;
	}
}
