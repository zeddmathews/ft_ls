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
	}
	if (flagString[0] == '-')
	{
		if (flags->foundOther > 0)
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

void	checkExists(char *flagString, t_ls *data)
{
	t_ls *head;

	head = data;
	while (data->fw)
	{
		wordMatch(flagString, data->fileName) == 0 ? ft_putendl(flagString) : invalidFOrD(flagString);
		data = data->fw;
	}
	data = head;
}

void	setPriority(is_set *flags)
{
	if (flags->dash_a == 1)
		flags->priority_a = 5;
	if (flags->dash_r == 1)
		flags->priority_r = 4;
	if (flags->dash_t == 1)
		flags->priority_t = 3;
	if (flags->dash_l == 1)
		flags->priority_l = 2;
	if (flags->dash_R == 1)
		flags->priority_R = 1;
}

int		flagCheck(int ac, char **av, is_set *flags)
{
	int avi;

	avi = 0;
	while (avi < ac)
	{
		if (doubleDash(ac, av[avi]) == 2)
			return (3);
		if (doubleDash(ac, av[avi]) == 1)
			return (2);
		if (findDash(av[avi], flags) == 2)
		{
			if (ft_strchr(av[avi], 'a'))
			{
				if (flags->dash_a == 1)
					continue ;
				else
					flags->dash_a = 1;
			}
			if (ft_strchr(av[avi], 'r'))
			{
				if (flags->dash_r == 1)
					continue ;
				else
					flags->dash_r = 1;
			}
			if (ft_strchr(av[avi], 't'))
			{
				if (flags->dash_t == 1)
					continue ;
				else
					flags->dash_t = 1;
			}
			if (ft_strchr(av[avi], 'l'))
			{
				if (flags->dash_l == 1)
					continue ;
				else
					flags->dash_l = 1;
			}
			if (ft_strchr(av[avi], 'R'))
			{
				if (flags->dash_R == 1)
					continue ;
				else
					flags->dash_R = 1;
			}
		}
		avi++;
	}
	return (0);
}

int		argCheck(int ac, char **av, is_set *flags, t_ls *data)
{
	int i;
	int avi;

	i = 0;
	avi = 0;
	if (flagCheck(ac, av, flags) == 3)
		return(3);
	if (flagCheck(ac, av, flags) == 2)
	{
		illegalOption(av[avi]);
		return(2);
	}
	while (avi < ac - 1)
	{
		if (findDash(av[avi], flags) == 2)
		{
			setPriority(flags);
			avi++;
			continue ;
		}
		else if(findDash(av[avi], flags) == 1)
		{
			avi++;
			continue ;
		}
		else if(findDash(av[avi], flags) == 0)
		{
			checkExists(av[avi], data);
			avi++;
			continue ;
		}
		avi++;
	}
	return (0);
}

// int		filterArguments(int ac, char **av)
// {
// 	int i;
// 	int avi;

// 	i = 0;
// 	avi = ac -1;
// 	if (ac > 1)
// 	{
// 		while (i < avi)
// 		{
// 			avi++;
// 		}
// 	}
// }