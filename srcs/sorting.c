#include "../includes/ft_ls.h"

void	sort_a(t_ls *tmp)
{
	t_ls		*head;
	char		*str;

	head = tmp;
	while (tmp->fw != NULL)
	{
		if (tmp->store == NULL)
			tmp = tmp->fw;
		if (ft_strcmp(tmp->store, tmp->fw->store) > 0)
		{
			str = tmp->store;
			tmp->store = tmp->fw->store;
			tmp->fw->store = str;
			tmp = head;
		}
		else
			tmp = tmp->fw;
	}
	tmp->fw = NULL;
	tmp = head;
}