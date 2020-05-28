#include "../includes/ft_ls.h"

void	invalidFOrD(char *flagString)
{
	ft_putstr("ft_ls: ");
	ft_putstr(flagString);
	ft_putendl(": No such file or directory");
}

void	illegalOption(char *flagString)
{
	(void)flagString;
	ft_putendl("ft_ls: illegal option -- -");
	ft_putendl("usage: ft_ls [-Ralrt] [file ...]");
}

// int		multipleDashes(char *flagString)
// {
// 	int i;
// 	int len;
// 	int ti;
// 	char *tmp;
	
// 	i = 0;
// 	len = ft_strlen(flagString);
// 	ti = 2;
// 	tmp = (char *)malloc(sizeof(char) * len + 1);
// 	if (flagString[0] == '-' && flagString[1] == '-' && flagString[2] == '\0')
// 	{
// 		ft_putendl("need basic ls");
// 		exit(1);
// 	}
// 	while (flagString[i])
// 	{
// 		if (flagString[0] == '-' && flagString[1] == '-')
// 		{
// 			tmp[0] = '-';
// 			tmp[1] = '-';
// 			if (flagString[i] != '-')
// 			{
// 				tmp[ti] = flagString[i];
// 				ti++;
// 			}
// 			if (ft_strchr("larRt", flagString[i]) && flagString[i + 1] == '\0')
// 			{
// 				ft_putendl("ft_ls: option '--a' is ambiguous; possibilities: none");
// 				exit(1);
// 			}
// 		}
// 		i++;
// 	}
// 	i = 1;
// 	while (flagString[i])
// 	{
// 		if (!ft_strchr("larRt", flagString[i]) && flagString[0] == '-')
// 		{
// 			ft_putstr("ft_ls: unrecognized option '");
// 			ft_putchar(flagString[i]);
// 			ft_putendl("'");
// 			exit(1);
// 		}
// 		i++;
// 	}
// 	return (1);
// }

// int		validFlags(char *flagString)
// {
// 	int i;

// 	i = 0;
// 	if (!multipleDashes(flagString))
// 		exit(1);
// 	while (flagString[i])
// 	{
// 		if (flagString[i] == '-')
// 			i++;
// 		if (!(ft_strchr("larRt", flagString[i])))
// 		{
// 			ft_putstr("ft_ls: invalid option -- '");
// 			ft_putchar(flagString[i]);
// 			ft_putendl("'");
// 			return (0);
// 		}
// 		i++;
// 	}
// 	return (1);
// }

