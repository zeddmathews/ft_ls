#include "../includes/ft_ls.h"

void	printPermissions(struct stat permissions)
{
	S_ISDIR(permissions.st_mode) ? ft_putchar('d') : ft_putchar('-');
	permissions.st_mode & S_IRUSR ? ft_putchar('r') : ft_putchar('-');
	permissions.st_mode & S_IWUSR ? ft_putchar('w') : ft_putchar('-');
	permissions.st_mode & S_IXUSR ? ft_putchar('x') : ft_putchar('-');
	permissions.st_mode & S_IRGRP ? ft_putchar('r') : ft_putchar('-');
	permissions.st_mode & S_IWGRP ? ft_putchar('w') : ft_putchar('-');
	permissions.st_mode & S_IXGRP ? ft_putchar('x') : ft_putchar('-');
	permissions.st_mode & S_IROTH ? ft_putchar('r') : ft_putchar('-');
	permissions.st_mode & S_IWOTH ? ft_putchar('w') : ft_putchar('-');
	permissions.st_mode & S_IXOTH ? ft_putchar('x') : ft_putchar('-');
	ft_putchar(' ');
}

void	printIDData(struct stat idData)
{
	struct group	*group;
	struct passwd	*pwd;

	if ((pwd = getpwuid(idData.st_uid)) != NULL)
	{
		ft_putstr(pwd->pw_name);
		ft_putchar(' ');
	}
	if ((group = getgrgid(idData.st_gid)) != NULL)
	{
		ft_putstr(group->gr_name);
		ft_putchar(' ');
	}
}

void	printTime(struct stat timeData)
{
	char	*time;

	time = ctime(&timeData.st_mtime);
	time = time + 4;
	printNString(time, 12);
}

void	userData(char *path)
{
	struct stat buff;

	if(stat(path,&buff) < 0)
		return ;
	printPermissions(buff);
	ft_putnbr(buff.st_nlink);
	ft_putchar('\t');
	printIDData(buff);
	if (ft_numlen(buff.st_size) < 2)
	{
		ft_putnbr(buff.st_size);
		ft_putchar(' ');
		ft_putchar('\t');
	}
	else
	{
		ft_putnbr(buff.st_size);
		ft_putchar('\t');
	}
	printTime(buff);
}

void	printEverything(t_ls *store, is_set *flags)
{
	printBlocks(store);
	while(store->fw)
	{
		if (!flags->dash_a)
		{
			if(store->fileName[0] == '.')
			{
				store = store->fw;
				continue ;
			}
		}
		userData(store->fileName);
		ft_putchar(' ');
		ft_putstr(store->fileName);
		ft_putchar('\n');
		store = store->fw;
	}
	store->fw = NULL;
}