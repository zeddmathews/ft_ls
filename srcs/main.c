#include "../includes/ft_ls.h"

int		main(int ac, char **av)
{
	t_ls *data;
	is_set *flags;
	// int flag;

	data = NULL;
	flags = (is_set *)malloc(sizeof(is_set));
	// flag = 0;
	if (ac == 1)
	{
		data = dataTypeName(".");
		sortAscii(data);
		printBase(data);
	}
	else if (ac > 1)
	{
		if(argCheck(ac, av, flags, data) == 3)
		{
			data = dataTypeName(".");
			sortAscii(data);
			printBase(data);
		}
		// else if(argCheck(ac, av, flags, data) == 2)
		// {
		// 	data = dataTypeName(".");
		// 	sortAscii(data);
		// 	printBase(data);
		// }
				// flag = flagCheck(av[1], flags);
				else if (flags->dash_a)
				{
					data = dataTypeName(".");
					sortAscii(data);
					printAll(data);
				}
				else if (flags->dash_r)
				{
					data = dataTypeName(".");
					sortRevAscii(data);
					printBase(data);
				}
				else if (flags->dash_t)
				{
					data = dataTypeName(".");
					sortTime(data);
					printBase(data);
				}
				else if (flags->dash_l)
				{
					data = dataTypeName(".");
					sortAscii(data);
					printEverything(data);
				}
				else if (flags->dash_R)
					dash_R(".", 0);
	}
	return (0);
}