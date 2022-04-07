#include "push_swap.h"

void	ft_char_listdelone(t_op *op, void (*del)(void *))
{
	if (!op || !del)
		return ;
	del(op);
}

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


t_op	*ft_char_listnew(char *operation)
{
	t_op	*first;

	first = malloc(sizeof(t_op));
	if (!first)
		return (NULL);
	first->operation = operation;
	first->next = NULL;
	return (first);
}

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
