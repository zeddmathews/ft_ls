/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmathews <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 13:44:56 by zmathews          #+#    #+#             */
/*   Updated: 2019/10/01 07:30:14 by zmathews         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	flagThings(char *str)
{
	if (str[1] == '-')
		ft_putendl("Double dash");
	else if (str[1] == 'l')
		ft_putendl("Does not -l");
	else if (str[1] == 'a')
		storeTypeName(str);
	else if (str[1] == 'r')
		ft_putendl("Does not -r");
	else if (str[1] == 'R')
		ft_putendl("Does not -R");
	else if (str[1] == 't')
		ft_putendl("Does not -t");
}

int		flagCheck(char *flagString, is_set *flags)
{
	// build error handlers
	if (ft_strchr(flagString, 'a'))
		flags->dash_a = 1;
	if (ft_strchr(flagString, 'r'))
		flags->dash_r = 1;
	if (ft_strchr(flagString, 't'))
		flags->dash_t = 1;
	if (ft_strchr(flagString, 'l'))
		flags->dash_l = 1;
	if (ft_strchr(flagString, 'R'))
		flags->dash_R = 1;
	return(1);
}