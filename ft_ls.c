// 42 Header

int	main(int ac, char **av)
{
	DIR *dir;
	struct dirent *sd;

	dir = opendir(".");
	if (dir == NULL)
		return (-1);
	while (sd = readdir(dir) != NULL)
		ft_putendl(sd->d_name);
	closedir(dir);
}
