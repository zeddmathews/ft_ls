#include "../includes/ft_ls.h"

t_ls	*dataTypeName(char *path)
{
	t_ls		*tmp;
	t_ls		*head;
	struct stat	block;
	DIR		*d_stream;
	struct dirent	*sd;

	tmp = (t_ls *)malloc(sizeof(t_ls));
	head = tmp;
	d_stream = opendir(path);
	while ((sd = readdir(d_stream)))
	{
		tmp->fileName = sd->d_name;
		tmp->block = block.st_blocks;
		lstat(tmp->fileName, &block);
		tmp->fw = (t_ls *)malloc(sizeof(t_ls));
		tmp = tmp->fw;
	}
	tmp->fw = NULL;
	tmp = head;
	closedir(d_stream);
	return (tmp);
}