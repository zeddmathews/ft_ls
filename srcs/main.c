#include "../includes/ft_ls.h"

int		main(int ac, char **av)
{
	t_ls *store;
	is_set *flags;
	int flag;

	store = NULL;
	flags = (is_set *)malloc(sizeof(is_set));
	flag = 0;
	if (ac == 1)
	{
		store = storeTypeName(".");
		sortAscii(store);
		printBase(store);
	}
	else if (ac > 1)
	{
				flag = flagCheck(av[1], flags);
				// ft_putnbr(flag);
				// ft_putnbr(flags->dash_a);
				// ft_putchar();
				if (flags->dash_a)
				{
					store = storeTypeName(".");
					sortAscii(store);
					printAll(store);
				}
				else if (flags->dash_r)
				{
					store = storeTypeName(".");
					sortRevAscii(store);
					printBase(store);
				}
				// ft_putchar('\n');
				// ft_putendl("welp");
	}
	return (0);
}