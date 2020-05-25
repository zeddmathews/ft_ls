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
// # include <linux/types.h>
// # include <linux/stat.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/stat.h>
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
	int					priority_a;
	int					dash_r;
	int					priority_r;
	int					dash_t;
	int					priority_t;
	int					dash_l;
	int					priority_l;
	int					dash_R;
	int					priority_R;
	int					dir_num;
}						is_set;

// void	flagThings(char *str);
int		isFlag(char *str);
t_ls	*storeTypeName(char *path);
t_ls	*no_options(char *path);
void	sortAscii(t_ls *tmp);
void	printAll(t_ls *list);
void	printBase(t_ls *list);
void	sortRevAscii(t_ls *tmp);
void	sortTime(t_ls *tmp);
int		timeCompare(char *s1, char *s2);
int		validFlags(char *flagString);
int		multipleDashes(char *flagString);
int		flagCheck(char *flagString, is_set *flags);
// t_ls	*store_recursive(char *path);

#endif