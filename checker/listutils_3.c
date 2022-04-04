#include "checker.h"

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
