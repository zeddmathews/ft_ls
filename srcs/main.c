#include "../includes/ft_ls.h"

int	main(int ac, char **av)
{
	t_ls	*hold;
	hold = store_current_dir(".");
	sort_a(hold);
	if (ac >= 2 && av[1][1] == 'a')
	{
		print_a(hold);
		return (0);
	}
	print_base(hold);
	return (0);
}