/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   security.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 16:16:37 by athirion          #+#    #+#             */
/*   Updated: 2022/04/13 16:34:08 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 ** Free and set to NULL.
 */

void	ft_free(void *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
}

/*
 ** Free NULL terminated a 2D tab.
 */

void	ft_free_tab(void **tab)
{
	void	**ptr;

	ptr = tab;
	while (*tab)
	{
		free(*tab);
		*tab = NULL;
		tab++;
	}
	free (ptr);
	ptr = NULL;
}

/*
 ** Parsing error function.
 */

void	ft_error(char **strtab, int *numtab)
{
	ft_free_tab((void **)strtab);
	free(numtab);
	ft_putstr_fd("Error\n", 2);
	exit (EXIT_FAILURE);
}

/*
 ** Clear memory and terminate.
 */

void	ft_clear_exit(t_data *data, int status)
{
	ft_free(data->tab);
	if (data->stack_a)
		ft_listclear(&data->stack_a, free);
	if (data->stack_b)
		ft_listclear(&data->stack_b, free);
	if (data->oplist)
		ft_char_listclear(&data->oplist, free);
	if (data->op)
		free(data->op);
	exit(status);
}
