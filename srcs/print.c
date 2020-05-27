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
void	printBase(t_ls *list)
{
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

	if (!(dir = opendir(str)))
		return;
	while ((store = readdir(dir)) != NULL) {
		if (store->d_type == DT_DIR) {
			if (store->d_name[0] == '.')
				continue;
			path = ft_strjoinmult(str, store->d_name, "/");
			ft_putindent(indent);
			ft_putendl(ft_strjoin("./",store->d_name));
			dash_R(path, indent + 2);
		} else {
		ft_putindent(indent);
		ft_putendl(store->d_name);
		}
	}
	closedir(dir);
}