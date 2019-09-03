/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmathews <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 13:55:21 by zmathews          #+#    #+#             */
/*   Updated: 2019/09/03 01:45:19 by zmathews         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		if (is_flag(av[1]) == 1)
		{
			flag_things(av[1]);
			return (0);
		}
/*		DIR *dir;
		struct dirent *sd;

		dir = opendir(".");
		if (dir == NULL)
		{
			ft_putendl("GTFO Muthafucka");
			exit (1);
		}
		while ((sd = readdir(dir)) != NULL)
			ft_putendl(sd->d_name);
		closedir(dir);
*/	}
	return (0);
}
