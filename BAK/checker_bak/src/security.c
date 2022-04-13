#include "checker.h"

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
 ** Free NULL terminated a 2D tab
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

void	ft_error(char **strtab, int *numtab)
{
	ft_free_tab((void **)strtab);
	free(numtab);
	ft_putstr_fd("Error\n", 2);
	exit (EXIT_FAILURE);
}
