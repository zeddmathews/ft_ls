#include "../includes/ft_ls.h"

int		main(int ac, char **av)
{
	(void)ac;
	if (validFlags(av[1]) == 1)
	{
		ft_putendl("welp");
	}
	return (0);
}