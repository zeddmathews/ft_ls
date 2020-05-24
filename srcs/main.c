#include "../includes/ft_ls.h"

int	main(int ac, char **av)
{
	t_ls	*hold;
	if (ac >= 2 && av[1][1] == 'a')
	{
		hold = storeTypeName(".");
		sortAscii(hold);
		printAll(hold);
		return (0);
	}
	else if (ac >= 2 && av[1][1] == 'r')
	{
		hold = storeTypeName(".");
		sortRevAscii(hold);
		printAll(hold);
		return (0);
	}
	// else if (ac >= 2 && av[1][1] == 'R')
	// {
	// 	hold = store_recursive(".");
	// 	sort_a(hold);
	// 	print_a(hold);
	// 	return (0);
	// }
	else if (ac == 1)
	{
		hold = storeTypeName(".");
		sortAscii(hold);
		printBase(hold);
		return (0);
	}
	else
		ft_putendl("You done fucked up");
	return (0);
}