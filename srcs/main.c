#include "../includes/ft_ls.h"

int		main(int ac, char **av)
{
	t_ls *store;

	store = NULL;
	if (ac == 1)
	{
		store = storeTypeName(".");
		sortAscii(store);
		printBase(store);
	}
	else if (ac > 1)
	{
		if (validFlags(av[1]) == 1)
			ft_putendl("welp");
	}
	return (0);
}