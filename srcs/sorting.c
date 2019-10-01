#include "../includes/ft_ls.h"
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned const char	*str1;
	unsigned const char	*str2;
	int					i;

	if (!s1 || !s2)
		return (-1);
	str1 = (unsigned const char *)s1;
	str2 = (unsigned const char *)s2;
	i = 0;
	while (str1[i] == str2[i] && str1[i] != '\0' && str2[i] != '\0')
		i++;
	return (str1[i] - str2[i]);
}

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

int	main(int ac, char **av)
{
	t_ls	*hold;
	hold = store_current_dir(".");
	sort_a(hold);
	if (ac >= 2 && av[1][1] == 'a')
	{
		print_a(hold);
		return (0);
	}
	print_base(hold);
	return (0);
}
