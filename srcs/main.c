#include "../includes/ft_ls.h"

int	main(int ac, char **av)
{
	t_ls	*hold;
	hold = store_type_name(".");
	sort_a(hold);
	if (ac >= 2 && av[1][1] == 'a')
	{
		print_a(hold);
		return (0);
	}
	else if (ac == 1)
		print_base(hold);
	else
		ft_putendl("You done fucked up");
	return (0);
}