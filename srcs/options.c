/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dash_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmathews <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 01:11:46 by zmathews          #+#    #+#             */
/*   Updated: 2019/09/06 16:47:29 by zmathews         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_ls	*store(char *path)
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

t_ls	*dash_l(char *path)
{
	struct stat	*ss;

}

t_ls	*dash_R(char *path)
{
	typedef struct		s_list
	{
		char		*name;
		char		*type;
		struct s_list 	*next;
	}			t_list;
	t_list		*tmp;
	t_list		*head;
	DIR		*d_stream;
	struct dirent	*sd;

	tmp = (t_list *)malloc(sizeof(t_list));
	d_stream = opendir(path);
	while (sd = readdir(d_stream))
	{
		if (sd->d_type == DT_DIR)
		{
			if (ft_strcmp(d_name , ".") == 0)
			{
				tmp = tmp->next;
				continue ;
			}
			else
				tmp->name = sd->d_name;
				tmp->type = sd->d_type;
				tmp->next = (t_list *)malloc(sizeof(t_list));
				tmp = tmp->next;
		}
	}

}
