/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmathews <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 11:29:56 by zmathews          #+#    #+#             */
/*   Updated: 2019/10/01 07:52:56 by zmathews         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	print_a(t_ls *list)
{
	while (list->fw != NULL)
	{
		ft_putendl(list->store);
		list = list->fw;
	}
	return ;
}
void	print_base(t_ls *list)
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
}
