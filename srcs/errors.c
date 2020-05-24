#include "../includes/ft_ls.h"

int		validFlags(char *flagString)
{
	int i;

	i = 0;
	while (flagString[i])
	{
		if (!(ft_strchr("larRt", flagString[i])))
		{
			ft_putendl(ft_strjoin("ft_ls: invalid option -- '", flagString[i]));
			ft_putchar("'");
			exit (1);
		}
		i++;
	}
	return (1);
}