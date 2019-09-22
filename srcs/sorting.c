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

/*t_ls	*something_here(char *path)
  {
  t_ls		*tmp;
  t_ls		*head;
  DIR		*d_stream;
  struct dirent	*sd;

  tmp = (t_ls *)malloc(sizeof(t_ls));
  head = tmp;
  d_stream = opendir(path);
  while (sd = readdir(d_stream))
  {
  tmp->store = sd->d_name;
  tmp->fw = (t_ls *)malloc(sizeof(t_ls));
  tmp = tmp->fw;
  }
  tmp->fw = NULL;
  tmp = head;
  return (tmp);
  }
  */
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
	t_ls *test;
	test = dash_a(".");
	sort_a(test);
	if (av[1] && av[1][1] == 'a')
	{
		while (test->fw != NULL)
		{
			printf("%s\n", test->store);
			test = test->fw;
		}
		return (0);
	}
	while (test->fw != NULL)
	{
		if (test->store[0] == '.')
		{
			test = test->fw;
			continue ;
		}
		printf("%s\n", test->store);
		test = test->fw;
	}
	return (0);
}
