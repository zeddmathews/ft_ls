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

int		timeCompare(char *s1, char *s2)
{
	struct stat time1;
	struct stat time2;

	stat(s1, &time1);
	stat(s2, &time2);
	if (time1.st_ctime == time2.st_ctime)
		return (time1.st_ctimespec.tv_nsec < time2.st_ctimespec.tv_nsec);
	return (time1.st_ctime < time2.st_ctime);
}

void	sortTime(t_ls *tmp)
{
	t_ls	*head;
	char	*str;

	head = (t_ls *)malloc(sizeof(t_ls));
	head = tmp;
	while (tmp->fw != NULL)
	{
		if (timeCompare(tmp->fileName, tmp->fw->fileName))
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