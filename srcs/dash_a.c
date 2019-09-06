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

void	dash_a(char *str, char *path)
{
	int i;
	DIR *d_stream;
	struct dirent *sd;

	i = 1;
	if (!(d_stream = opendir(path)))
		return ;
	while (str[i])
	{
		while ((sd = readdir(d_stream)))
			ft_putendl(sd->d_name);
		i++;
	}
}
