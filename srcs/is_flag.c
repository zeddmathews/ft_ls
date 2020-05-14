/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmathews <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 13:48:16 by zmathews          #+#    #+#             */
/*   Updated: 2019/09/03 01:45:33 by zmathews         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
// #include <unistd.h>
// void	ft_putchar(int letter)
// {
// 	write(1, &letter, 1);
// }

// void	ft_putendl(char *str)
// {
// 	int i = 0;
// 	while (str[i])
// 	{
// 		ft_putchar(str[i]);
// 		i++;
// 	}
// }

int		is_flag(char *str)
{
	if (str[0] == '-')
		return (1);
	return (0);
}

// int		main(int ac, char**av)
// {
// 	if (is_flag(av[1]))
// 		ft_putendl(av[1]);
// 	return (0);
// }
