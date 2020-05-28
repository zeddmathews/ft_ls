#include "../includes/ft_ls.h"


is_set	*create_flag_space(void)
{
	is_set  *flags;

	flags = (is_set *)malloc(sizeof(is_set));
	flags->dash_a = 0;
	flags->dash_r = 0;
	flags->dash_t = 0;
	flags->dash_l = 0;
	flags->dash_R = 0;
	return (flags);
}

int		main(int ac, char **av)
{
	t_ls *data;
	is_set *flags;
	int avi;

	data = NULL;
	flags = NULL;
	avi = 1;
	if (ac == 1)
		printBasic(data);
	else if (ac > 1)
	{
		data = dataTypeName(".");
		flags = create_flag_space();
		flagCheck(ac, av, flags, data);
		if (findDash(av[avi], flags) == 3)
		{
			while (avi < ac)
			{
				data = dataTypeName(".");
				checkExists(av[avi], data, flags);
				listDel(data);
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
			else if (flags->dash_l == 1)
				printDashl(data);
			else if (flags->dash_R)
				dash_R(".", 0);
		}
		
	}
	return (0);
}