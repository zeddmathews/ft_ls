#include "../includes/ft_ls.h"

void	printAll(t_ls *list)
{
	while (list->fw != NULL)
	{
		ft_putendl(list->fileName);
		list = list->fw;
	}
	return ;
}
void	printBase(t_ls *list)
{
	while (list->fw != NULL)
	{
		if (list->fileName[0] == '.')
		{
			list = list->fw;
			continue ;
		}
		ft_putendl(list->fileName);
		list = list->fw;
	}
}

void	printNString(char *str, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		ft_putchar(str[i]);
		i++;
	}
}