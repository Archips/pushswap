#include "push_swap.h"

/*
 ** Delete a list
 */

void	ft_listclear(t_lst **lst, void (*del)(void *))
{
	t_lst	*ptr;

	ptr = *lst;
	while (ptr != NULL)
	{
		*lst = (*lst)->next;
		ft_listdelone(ptr, del);
		ptr = *lst;
	}
}

/*
 ** Delete one list element
 */

void	ft_listdelone(t_lst *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst);
}

/*
 ** Return the last element of a list
 */

t_lst	*ft_listlast(t_lst *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

/*
 ** Create one list element
 */

t_lst	*ft_listnew(int content, t_data *data)
{
	t_lst	*first;

	first = malloc(sizeof(t_lst));
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
	first->content = content;
	first->next = NULL;
	return (first);
}

/*
 ** Return a list size
 */

int	ft_listsize(t_lst *lst)
{
	int	count;

	count = 0;
	while (lst)
		lst = (count++, lst->next);
	return (count);
}
