#include "../includes/ft_ls.h"

t_ls	*storeTypeName(char *path)
{
	t_ls		*tmp;
	t_ls		*head;
	DIR		*d_stream;
	struct dirent	*sd;

	tmp = (t_ls *)malloc(sizeof(t_ls));
	head = tmp;
	d_stream = opendir(path);
	while ((sd = readdir(d_stream)))
	{
		tmp->fileName = sd->d_name;
		tmp->fw = (t_ls *)malloc(sizeof(t_ls));
		tmp = tmp->fw;
	}
	tmp->fw = NULL;
	tmp = head;
	return (tmp);
}