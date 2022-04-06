#include "push_swap.h"

/* typedef struct s_buf */
/* { */
/* 	struct s_buf	*next; */
/* 	char			*op; */
/* } */

void	ft_add_op(char *operation, t_buf **list)
{
	t_buf   *new;
	t_buf	*temp;

	new	= (t_buf *)malloc(sizeof(t_buf));
	if (!new)
		return ;
	new->op = operation;
	ft_printf("%s\n", new->op);
	new->next = NULL;
	if (!list)
	{
		*list = new;
		return ;
	}
	temp = *list;
	ft_printf("HEAD LIST -> [%s]\n", temp->op);
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}



