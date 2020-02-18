/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmathews <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 13:48:57 by zmathews          #+#    #+#             */
/*   Updated: 2019/10/01 07:54:55 by zmathews         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "../libft/libft.h"

typedef struct		s_ls
{
	char		*store;
	struct s_ls	*fw;
}			t_ls;
void	flag_things(char *str);
int		is_flag(char *str);
t_ls	*store_current_dir(char *path);
t_ls	*no_options(char *path);
void	sort_a(t_ls *tmp);
void	print_a(t_ls *list);
void	print_base(t_ls *list);

#endif