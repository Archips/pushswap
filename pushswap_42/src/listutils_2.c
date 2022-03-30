#include "push_swap.h"

void	ft_listprint_int(t_lst *lst)
{
	t_lst	*temp;

	temp = lst;
	printf("(front)");
	while (temp)
	{
		printf(" [cn=%i,id=%i,sp=%i,cs=%i] ->\n",
				temp->content,
				temp->id,
				temp->senpai,
				temp->cost
				);
		temp = temp->next;
	}
	printf(" NULL (back)\n");
	printf("\n");
}

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

void	ft_listadd_front(t_lst **alst, t_lst *new)
{
	if (!alst || !new)
		return ;
	new->next = *alst;
	*alst = new;
}

