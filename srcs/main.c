#include "../includes/ft_ls.h"

int		main(int ac, char **av)
{
	t_ls *data;
	is_set *flags;
	int flag;

	store = NULL;
	flags = (is_set *)malloc(sizeof(is_set));
	flag = 0;
	if (ac == 1)
		printBasic(data);
	else if (ac > 1)
	{
				flag = flagCheck(av[1], flags);
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
	return (0);
}