// 42 Header

#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putendl(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
	ft_putchar('\n');
}

int	main(int ac, char **av)
{
		DIR *dir;
		struct dirent *sd;

		dir = opendir(".");
		if (dir == NULL)
		{
			ft_putendl("GTFO Muthafucka");
			exit (1);
		}
		while ((sd = readdir(dir)) != NULL)
			ft_putendl(sd->d_name);
		closedir(dir);
		return (0);
}
