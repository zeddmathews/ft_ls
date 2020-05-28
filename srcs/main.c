#include "../includes/ft_ls.h"

int		main(int ac, char **av)
{
	t_ls *data;
	is_set *flags;
	int flag;
	int avi;

	data = NULL;
	flags = (is_set *)malloc(sizeof(is_set));
	flag = 0;
	avi = 1;
	if (ac == 1)
		printBasic(data);
	else if (ac > 1)
	{
		data = dataTypeName(".");
		flag = flagCheck(ac, av, flags, data);
		if (findDash(av[avi], flags) == 3)
		{
			while (avi < ac)
			{
				data = dataTypeName(".");
				// ft_putendl(av[1]);
				checkExists(av[avi], data);
				avi++;
			}
				return (0);
		}
		else
		{
			if (flags->dash_a)
				printDasha(data);
			else if (flags->dash_r)
				printDashr(data);
			else if (flags->dash_t)
				printDasht(data);
			else if (flags->dash_l)
				printDashl(data);
			else if (flags->dash_R)
				dash_R(".", 0);
		}
		
	}
	return (0);
}
// if(argCheck(ac, av, flags, data) == 3)
		// {
		// 	data = dataTypeName(".");
		// 	sortAscii(data);
		// 	printBase(data);
		// }
		// else if(argCheck(ac, av, flags, data) == 2)
		// 	return(0);
		// {
		// 	data = dataTypeName(".");
		// 	sortAscii(data);
		// 	printBase(data);
		// }
				// flag = flagCheck(av[1], flags);