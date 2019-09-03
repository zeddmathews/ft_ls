/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmathews <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 13:44:56 by zmathews          #+#    #+#             */
/*   Updated: 2019/09/03 01:45:44 by zmathews         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	flag_things(char *str)
{
	if (str[1] == '-')
		ft_putendl("Double dash");
	else if (str[1] == 'l')
		ft_putendl("Does not -l");
	else if (str[1] == 'a')
		dash_a(str, ".");
	else if (str[1] == 'r')
		ft_putendl("Does not -r");
	else if (str[1] == 'R')
		ft_putendl("Does not -R");
	else if (str[1] == 't')
		ft_putendl("Does not -t");
}
