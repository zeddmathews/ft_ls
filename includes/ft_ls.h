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
# include <linux/types.h>
# include <linux/stat.h>
// # include <sys/types.h>
// # include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include "../libft/includes/libft.h"

typedef struct			s_ls
{
	char				*fileName;
	struct s_ls			*fw;
}						t_ls;

typedef struct			user_data
{
	struct user_data	*fw;
}						l_flag;

typedef struct 			set_flag
{
	int					dash_a;
	int					dash_r;
	int					dash_t;
	int					dash_l;
	int					dash_R;
	int					dir_num;
}						is_set;


void	flag_things(char *str);
int		is_flag(char *str);
t_ls	*store_type_name(char *path);
t_ls	*no_options(char *path);
void	sort_a(t_ls *tmp);
void	print_a(t_ls  *list);
void	print_base(t_ls *list);
void	sort_r(t_ls *tmp);
t_ls	*store_recursive(char *path);

#endif
