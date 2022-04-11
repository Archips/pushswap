#include "push_swap.h"

/*
 ** Find the node with the smallest content.
 */

t_lst	*ft_listmin(t_lst *lst)
{
	t_lst	*min;
	t_lst	*temp;

	min = lst;
	temp = lst;
	while (temp)
	{
		if (temp->content < min->content)
			min = temp;
		temp = temp->next;
	}
	return (min);
}

/*
 ** Find the node with the highest content.
 */

t_lst	*ft_listmax(t_lst *lst)
{
	t_lst	*max;
	t_lst	*temp;

	max = lst;
	temp = lst;
	while (temp)
	{
		if (temp->content > max->content)
			max = temp;
		temp = temp->next;
	}
	return (max);
}

/*
 ** Check that a numerical list is sorted
 */

int	ft_listissort(t_lst *lst)
{
	t_lst	*temp_1;
	t_lst	*temp_2;

	temp_1 = lst;
	while (temp_1)
	{
		temp_2 = temp_1->next;
		while (temp_2)
		{
			if (temp_1->content > temp_2->content)
				return (0);
			temp_2 = temp_2->next;
		}
		temp_1 = temp_1->next;
	}
	return (1);
}
