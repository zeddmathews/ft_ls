/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmathews <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 13:55:21 by zmathews          #+#    #+#             */
/*   Updated: 2019/09/06 19:13:44 by zmathews         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int	main(int ac, char **av)
{
/*	DIR	*stream;
	struct dirent *thing;
	if (ac == 1)
	{
		stream = opendir(".");

	}
*/	if (ac == 2)
	{
		if (is_flag(av[1]) == 1)
		{
			flag_things(av[1]);
			return (0);
		}
	}
	return (0);
}
