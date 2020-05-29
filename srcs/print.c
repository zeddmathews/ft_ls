#include "../includes/ft_ls.h"

void	printAll(t_ls *list)
{
	while (list->fw != NULL)
	{
		ft_putendl(list->fileName);
		list = list->fw;
	}
	return ;
}
void	printBase(t_ls *a)
{
    t_ls *list;

    list = a;
	while (list->fw != NULL)
	{
		if (list->fileName[0] == '.')
		{
			list = list->fw;
			continue ;
		}
		ft_putendl(list->fileName);
		list = list->fw;
	}
}

void	printNString(char *str, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	dash_R(char *str, int indent)
{
	DIR *dir;
	struct dirent *store;
	char *path;
	char *tmp;

	if (!(dir = opendir(str)))
		return;
	while ((store = readdir(dir)) != NULL)
	{
		if (store->d_type == DT_DIR)
		{
			if (store->d_name[0] == '.')
				continue;
			path = ft_strjoinmult(str, store->d_name, "/");
			ft_putindent(indent);
			tmp = ft_strjoin("./", store->d_name);
			ft_putendl(tmp);
			free(tmp);
			dash_R(path, indent + 2);
			free(path);
		}
		else
		{
			ft_putindent(indent);
			ft_putendl(store->d_name);
		}
	}
	closedir(dir);
}

void	printBasic(t_ls *data)
{
	data = dataTypeName(".");
	sortAscii(data);
	printBase(data);
	listDel(data);
}

void	multipleFlags(t_ls *data, is_set *flags)
{
	if (flags->dash_R)
		dash_R(".", 0);
	else if (flags->dash_a)
	{
		data = dataTypeName(".");
		sortAscii(data);
		if (flags->dash_r)
			sortRevList(data);
		if (flags->dash_t)
			sortTime(data, flags);
		if (flags->dash_l)
			printEverything(data, flags);
		else if (!flags->dash_l)
			printAll(data);
	}
	else if (!flags->dash_a)
	{
		data = dataTypeName(".");
		sortAscii(data);
		if (flags->dash_r)
			sortRevList(data);
		if (flags->dash_t)
			sortTime(data, flags);
		if (flags->dash_l)
			printEverything(data, flags);
		else if (!flags->dash_l)
			printBase(data);
	}
}