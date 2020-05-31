#include "../includes/ft_ls.h"

int		doubleDash(int ac, char *flagString)
{
	int len;

	len = ft_strlen(flagString);
	if (ac >= 2 && flagString[0] == '-' && flagString[1] == '-' && len > 2)
		return (1);
	else if (ac >= 2 && flagString[0] == '-' && flagString[1] == '-' && len == 2)
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
	return (0);
}

void	flagCheck(int ac, char **av, is_set *flags, t_ls *data)
{
	int avi;

	avi = 1;
	while (avi < ac)
	{
		if (doubleDash(ac, av[avi]) == 2)
		{
			printBasic(data);
			exit (1);
		}
		if (doubleDash(ac, av[avi]) == 1)
		{
			illegalOption(av[avi][1]);
			exit (1);
		}
		flagCheck1(av, avi, flags, data);
		avi++;
	}
}

void	flagCheck1(char **av, int avi, is_set *flags, t_ls *data)
{
	int i;

	i = 1;
	if (av[avi][0] == '-')
		{
			while (av[avi][i])
			{
				if (!ft_strchr("larRt", av[avi][i]))
				{
					illegalOption(av[avi][i]);
					exit (1);
				}
				i++;
			}
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
}