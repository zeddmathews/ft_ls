#include "../includes/ft_ls.h"

void	printBlocks(t_ls *store)
{
	t_ls *data = store;
	int num;
	struct stat blocks;
	num = 0;
	while(data->fw != NULL)
	{
		if(stat(data->fileName,&blocks) < 0)
			return ;
		num += blocks.st_blocks;
		data = data->fw;
	}
	ft_putstr("total ");
	ft_putnbr(num);
	ft_putchar('\n');
}