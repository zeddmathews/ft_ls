#include "../includes/ft_ls.h"

void	printBlocks(t_ls *store)
{
	t_ls *tmp;
	int i;

	tmp = store;
	i = 0;
	ft_putstr("total ");
	while (tmp->fw)
	{
		if (tmp->fileName[0] == '.')
		{
			tmp = tmp->fw;
			continue ;
		}
		else
			i += tmp->block;
		tmp = tmp->fw;
	}
	ft_putnbr(i);
	ft_putstr("\n");
}