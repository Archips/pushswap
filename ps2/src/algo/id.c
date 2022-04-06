#include "push_swap.h"

/*
 ** Set IDs
 **
 ** Set the stack nodes ids.
 ** Return the stack len.
 */

int	ft_set_ids(t_lst *stack)
{
	int		i;
	t_lst	*temp;

	i = 0;
	if (!stack)
		return (0);
	temp = stack;
	while (temp && temp->next)
	{
		temp->id = i++;
		temp = temp->next;
	}
	temp->id = i;
	return (i + 1);
}
