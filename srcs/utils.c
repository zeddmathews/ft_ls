#include "../includes/ft_ls.h"

is_set	*setFlags(void)
{
	is_set  *flags;

	// flags = NULL;
	flags = (is_set *)malloc(sizeof(is_set));
	flags->dash_a = 0;
	flags->dash_r = 0;
	flags->dash_t = 0;
	flags->dash_l = 0;
	flags->dash_R = 0;
	return (flags);
}

void	freeFlags(is_set *flags)
{
	free(flags);
}

void	initMain(int ac, char **av, int avi, t_ls *data, is_set *flags)
{
	while (avi < ac)
	{
		data = dataTypeName(".");
		checkExists(av[avi], data, flags);
		listDel(data);
		avi++;
	}
}
// void	freeFlags(is_set *flags)
// {
// 	is_set *traverse;

// 	while (flags)
// 	{
// 		traverse = data;
// 	}
// 	free(flags);
// }

void	listDel(t_ls *data)
{
	t_ls *traverse;

	while (data)
	{
		traverse = data;
		data = data->fw;
		free(traverse);
	}
}