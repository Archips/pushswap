#include "push_swap.h"

/*
 ** Print a list
 */

void	ft_listprint_int(t_lst *lst)
{
	t_lst	*temp;

	temp = lst;
	while (temp)
	{
		ft_printf(" [ cn %i, id %i, sp %i, cs %i ] ->\n",
			temp->content,
			temp->id,
			temp->senpai,
			temp->cost
			);
		temp = temp->next;
	}
	ft_printf(" NULL (back)\n");
	ft_printf("\n");
}

/*
 ** Delete the first element of a list
 */

void	ft_listdelfirst(t_lst **lst, void (*del)(void *))
{
	t_lst	*temp;

	temp = *lst;
	if (!temp)
		return ;
	if (!temp->next)
	{
		ft_listdelone(temp, del);
		return ;
	}
	*lst = (*lst)->next;
	ft_listdelone(temp, del);
}

/*
 ** Delete the last element of a list
 */

void	ft_listdellast(t_lst **lst, void (*del)(void *))
{
	t_lst	*temp;

	temp = *lst;
	if (!temp)
		return ;
	if (!temp->next)
	{
		ft_listdelone(temp, del);
		return ;
	}
	while (temp->next->next)
		temp = temp->next;
	ft_listdelone(temp->next, del);
	temp->next = NULL;
}

/*
 ** Add an element to the back of the list
 */

void	ft_listadd_back(t_lst **alst, t_lst *new)
{
	t_lst	*cpy;

	if (!new)
		return ;
	if (!*alst)
	{
		*alst = new;
		return ;
	}
	cpy = *alst;
	while (cpy->next)
		cpy = cpy->next;
	cpy->next = new;
}

/*
 ** Add an element to the front of the list
 */

void	ft_listadd_front(t_lst **alst, t_lst *new)
{
	if (!alst || !new)
		return ;
	new->next = *alst;
	*alst = new;
}
