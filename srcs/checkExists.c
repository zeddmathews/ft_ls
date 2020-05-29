#include "../includes/ft_ls.h"

void	checkExists(char *flagString, t_ls *data, is_set *flags)
{
	t_ls *head;
	struct stat permissions;

	head = data;
	while (data->fw)
	{
		if (wordMatch(flagString, data->fileName) == 0)
		{
			lstat(flagString, &permissions);
			if (S_ISDIR(permissions.st_mode))
			{
				checkExists1(flagString, data);
				return ;
			}
			if (flags->dash_l)
			{
				checkExists2(flagString, data);
				return ;
			}
			else
				ft_putendl(flagString);
			return ;
		}
		data = data->fw;
	}
}

void	checkExists1(char *flagString, t_ls *data)
{
	
	ft_putendl(flagString);
	data = dataTypeName(flagString);
	sortAscii(data);
	printBase(data);
		
}

void	checkExists2(char *flagString, t_ls *data)
{
	while (wordMatch(data->fileName, flagString) != 0)
		data = data->fw;
	userData(data->fileName);
	ft_putchar(' ');
	ft_putstr(data->fileName);
	ft_putchar('\n');
}