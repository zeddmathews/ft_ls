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
	while ((store = readdir(dir)) != NULL) {
		if (store->d_type == DT_DIR) {
			if (store->d_name[0] == '.')
				continue;
			path = ft_strjoinmult(str, store->d_name, "/");
			ft_putindent(indent);
            tmp = ft_strjoin("./", store->d_name);
            ft_putendl(tmp);
             free(tmp);
			dash_R(path, indent + 2);
            free(path);
		} else {
		ft_putindent(indent);
		ft_putendl(store->d_name);
		}
	}
	closedir(dir);
}
void	printDasha(t_ls *data)
{
	data = dataTypeName("."); 
    sortAscii(data);
	printAll(data);
	listDel(data);
}

void	printDashr(t_ls *data)
{
	data = dataTypeName(".");
    
    sortRevList(data);
  	printBase(data);
	listDel(data);
}

void	printDasht(t_ls *data)
{
	data = dataTypeName(".");
	sortTime(data);
	printBase(data);
	listDel(data);
}

void	printDashl(t_ls *data)
{
	data = dataTypeName(".");
	sortAscii(data);
	printEverything(data);
	listDel(data);
}

void	printBasic(t_ls *data)
{
	data = dataTypeName(".");
	sortAscii(data);
	printBase(data);
    listDel(data);
}


void    listDel(t_ls *data)
{
    t_ls    *trav;

    while (data)
    {
        trav = data;
        data = data->fw;
        free(trav);
    }
}

/*
void	listDel(t_ls *data)
{
	t_ls *current;
	t_ls *fw;

	current = data;
	while (current->fw != NULL)
		current = current->fw;
	fw = current->fw;
	free(fw);
}*/
