#include "push_swap.h"

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

void	ft_listdelone(t_lst *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst);
}

t_lst	*ft_listlast(t_lst *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_lst	*ft_listnew(int content)
{
	t_lst	*first;

	first = malloc(sizeof(t_lst));
	if (!first)
		return (NULL);
	first->content = content;
	first->next = NULL;
	return (first);
}

int	ft_listsize(t_lst *lst)
{
	int	count;

	count = 0;
	while (lst)
		lst = (count++, lst->next);
	return (count);
}
