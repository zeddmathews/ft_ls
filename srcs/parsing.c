#include "../includes/ft_ls.h"

int		doubleDash(int ac, char *flagString)
{
	int len;

	len = ft_strlen(flagString);
	if (ac == 2 && flagString[0] == '-' && flagString[1] == '-' && len > 2)
		return (1);
	else if (ac == 2 && flagString[0] == '-' && flagString[1] == '-' && len == 2)
		return (2);
	else
		return(0);
}

int		findDash(char *flagString, is_set *flags)
{
	int foundFlags;
	int foundOther;

	foundFlags = 0;
	foundOther = 0;
	if (flagString[0] != '-')
	{
		foundOther += 1;
		flags->foundOther = 1;
		return (3);
	}
	else if (flagString[0] == '-')
	{
		if (flags->foundOther >= 1)
		{
			invalidFOrD(flagString);
			return (1);
		}
		else
		{
			foundFlags += 1;
			flags->foundFlag = foundFlags;
			return (2);
		}
	}
	return (0);
}

void	checkExists(char *flagString, t_ls *data, is_set *flags)
{
	t_ls *head;

	head = data;
	struct stat permissions;
	while (data->fw)
	{
		if (wordMatch(flagString, data->fileName) == 0)
		{
			lstat(flagString, &permissions);
			if (S_ISDIR(permissions.st_mode))
			{
				ft_putendl(flagString);
				data = dataTypeName(flagString);
				sortAscii(data);
				printBase(data);
				return ;
			}
			if (flags->dash_l)
			{
				while (wordMatch(data->fileName, flagString) != 0)
					data = data->fw;
				userData(data->fileName);
				ft_putchar(' ');
				ft_putstr(data->fileName);
				ft_putchar('\n');
			}
			else
				ft_putendl(flagString);
			return ;
		}
		data = data->fw;
	}
	invalidFOrD(flagString);
	data = head;
	listDel(data);
	listDel(head);
}

// void	setPriority(is_set *flags)
// {
// 	if (flags->dash_a == 1)
// 		flags->priority_a = 5;
// 	if (flags->dash_r == 1)
// 		flags->priority_r = 4;
// 	if (flags->dash_t == 1)
// 		flags->priority_t = 3;
// 	if (flags->dash_l == 1)
// 		flags->priority_l = 2;
// 	if (flags->dash_R == 1)
// 		flags->priority_R = 1;
// }

int		flagCheck(int ac, char **av, is_set *flags, t_ls *data)
{
	int avi;

	avi = 1;
	while (avi < ac)
	{
		if (doubleDash(ac, av[avi]) == 2)
			return (3);
		if (doubleDash(ac, av[avi]) == 1)
			return (2);
		if (av[avi][0] == '-')
		{
			if (ft_strchr(av[avi], 'a'))
				flags->dash_a = 1;
			if (ft_strchr(av[avi], 'r'))
				flags->dash_r = 1;
			if (ft_strchr(av[avi], 't'))
				flags->dash_t = 1;
			if (ft_strchr(av[avi], 'l'))
				flags->dash_l = 1;
			if (ft_strchr(av[avi], 'R'))
				flags->dash_R = 1;
		}
		else if (av[avi][0] != '-')
		{
			checkExists(av[avi], data, flags);
			exit(1);
		}
		avi++;
	}
	return (0);
}

// int		argCheck(int ac, char **av, is_set *flags, t_ls *data)
// {
// 	int i;
// 	int avi;

// 	i = 0;
// 	avi = 1;
// 	if (flagCheck(ac, av, flags, data) == 3)
// 		return(3);
// 	if (flagCheck(ac, av, flags, data) == 2)
// 	{
// 		illegalOption(av[avi]);
// 		return(2);
// 	}
// 	while (avi < ac)
// 	{
// 		if (findDash(av[avi], flags) == 2)
// 		{
// 			setPriority(flags);
// 			avi++;
// 			continue ;
// 		}
// 		else if(findDash(av[avi], flags) == 1)
// 		{
// 			avi++;
// 			continue ;
// 		}
// 		else if(findDash(av[avi], flags) == 0)
// 		{
// 			checkExists(av[avi], data, flags);
// 			avi++;
// 			continue ;
// 		}
// 		avi++;
// 	}
// 	return (0);
// }