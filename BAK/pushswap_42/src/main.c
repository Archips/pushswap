#include "push_swap.h"

/*
 ** Initialize stack A and stack B
 */

static void	ft_init_stacks(t_data *data)
{
	int	i;
	int	*tab_ptr;

	data->stack_b = ft_listnew(0);
	tab_ptr = data->tab;
	data->stack_a = ft_listnew(*(data)->tab++);
	i = 0;
	while (i++ < (int)data->tab_size - 1)
		ft_listadd_back(&data->stack_a, ft_listnew(*(data)->tab++));
	data->tab = tab_ptr;
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac > 1)
	{
		ft_parser(&data, ac, av);
		if (!data.tab)
			return (ft_putstr_fd("Error\n", 2), 1);

		ft_init_stacks(&data);
		if (!ft_issort(data.stack_a))
			ft_sort(&data);

		ft_listclear(&data.stack_a, free);
		ft_listclear(&data.stack_b, free);
		ft_free(data.tab);
	}
	return (0);
}
