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
			if (S_ISDIR(permissions.st_mode) && flags->dash_l)
				checkExists3(flagString, data, flags);
			if (S_ISDIR(permissions.st_mode))
				checkExists1(flagString, data);
			if (flags->dash_l)
				checkExists2(flagString, data);
			else
				ft_putendl(flagString);
			return ;
		}
		data = data->fw;
	}
	invalidFOrD(flagString);
}

void	checkExists1(char *flagString, t_ls *data)
{
	
	while (data->fw && wordMatch(data->fileName, flagString) != 0)
		data = data->fw;
	if (wordMatch(data->fileName, flagString) == 0)
	{
		ft_putstr(flagString);
		ft_putchar('/');
		ft_putchar('\n');
		data = dataTypeName(flagString);
		sortAscii(data);
		printBase(data);
		exit (1);
	}
	else
		invalidFOrD(flagString);
}

void	checkExists2(char *flagString, t_ls *data)
{
	while (data->fw && wordMatch(data->fileName, flagString) != 0)
		data = data->fw;
	if (wordMatch(data->fileName, flagString) == 0)
	{
		userData(data->fileName);
		ft_putchar(' ');
		ft_putstr(data->fileName);
		ft_putchar('\n');
		exit (1);
	}
	else
		invalidFOrD(flagString);
}

void	checkExists3(char *flagString, t_ls *data, is_set *flags)
{
	while (data->fw && wordMatch(data->fileName, flagString) != 0)
		data = data->fw;
	if (wordMatch(data->fileName, flagString) == 0)
	{
		data = dataTypeName(flagString);
		sortAscii(data);
		// printBlocks(data);
		printEverything(data, flags);
		exit (1);
	}
	else
		invalidFOrD(flagString);
}