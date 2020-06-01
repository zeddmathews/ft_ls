#include "../includes/ft_ls.h"

void	printBlocks(t_ls *store)
{
	t_ls *data = store;
	int total;
	struct stat blocks;

	total = 0;
	while(data->fw != NULL)
	{
		lstat(data->fileName,&blocks);
		total = total + blocks.st_blocks;
		data = data->fw;
	}
	ft_putstr("total ");
	ft_putnbr(total);
	ft_putchar('\n');
}