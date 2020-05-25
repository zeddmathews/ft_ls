#include "../includes/ft_ls.h"

void	sortAscii(t_ls *tmp)
{
	t_ls		*head;
	char		*str;

	head = (t_ls *)malloc(sizeof(t_ls));
	head = tmp;
	while (tmp->fw != NULL)
	{
		if (tmp->fileName == NULL)
			tmp = tmp->fw;
		if (ft_strcmp(tmp->fileName, tmp->fw->fileName) > 0)
		{
			str = tmp->fileName;
			tmp->fileName = tmp->fw->fileName;
			tmp->fw->fileName = str;
			tmp = head;
		}
		else
			tmp = tmp->fw;
	}
	tmp->fw = NULL;
	tmp = head;
}

void	sortRevAscii(t_ls *tmp)
{
	t_ls		*head;
	char		*str;

	head = (t_ls *)malloc(sizeof(t_ls));
	head = tmp;
	while (tmp->fw->fileName != NULL)
	{
		if (tmp->fileName == NULL)
			tmp = tmp->fw;
		if (ft_strcmp(tmp->fileName, tmp->fw->fileName) < 0)
		{
			str = tmp->fileName;
			tmp->fileName = tmp->fw->fileName;
			tmp->fw->fileName = str;
			tmp = head;
		}
		else
			tmp = tmp->fw;
	}
	tmp->fw = NULL;
	tmp = head;
}

// void	sortTime(t_ls *tmp)
// {
// 	t_ls	*head;
// 	char	*str;
// }