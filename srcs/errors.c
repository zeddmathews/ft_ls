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