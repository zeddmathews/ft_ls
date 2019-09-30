/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmathews <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 11:29:56 by zmathews          #+#    #+#             */
/*   Updated: 2019/09/30 12:30:18 by zmathews         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		print_flag(t_ls *list, char *flag)
{
	t_ls	*begin;
	begin = list;
	sort_a(list);
	if (is_flag(flag) && flag[1] == 'a')
	{
		while (list->fw != NULL)
		{
			ft_putendl(list->store);
			list = list->fw;
		}
		return (0);
	}
	else if (!(is_flag(flag)))
	{
		while (list->fw != NULL)
		{
			if (list->store[0] == '.')
			{
				list = list->fw;
				continue ;
			}
			ft_putendl(list->store);
			list = list->fw;
		}
		return (0);
	}
	return (0);
}
