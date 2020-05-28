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
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <time.h>
# include "../libft/includes/libft.h"

// readlink, getgrgid, getpwuid, maybe ctime

typedef struct			s_ls
{
	char				*fileName;
	int					block;
	struct s_ls			*fw;
}						t_ls;

// typedef struct			user_data
// {
// 	struct user_data	*fw;
// }						l_flag;

typedef struct 			set_flag
{
	int					dash_a;
	int					dash_r;
	int					dash_t;
	int					dash_l;
	int					dash_R;
	int					foundFlag;
	int					foundOther;
	int					dir_num;
}						is_set;

// void	flagThings(char *str);
int		isFlag(char *str);
t_ls	*dataTypeName(char *path);
t_ls	*no_options(char *path);
void	sortAscii(t_ls *tmp);
void	printAll(t_ls *list);
void	printBase(t_ls *list);
void	sortRevList(t_ls *tmp);
void	sortTime(t_ls *tmp);
int		timeCompare(char *s1, char *s2);
// int		validFlags(char *flagString);
// int		multipleDashes(char *flagString);
// int		flagCheck(char *flagString, is_set *flags);
void	flagCheck(int ac, char **av, is_set *flags, t_ls *data);
void	flagCheck1(char **av, int avi, is_set *flags, t_ls *data);
void	printNString(char *str, int len);
void	printPermissions(struct stat permissions);
void	printIDData(struct stat idData);
void	printTime(struct stat timeData);
void	userData(char *path);
void	printEverything(t_ls *store, is_set *flags);
void	printBlocks(t_ls *store);
void	dash_R(char *path, int indent);
void	invalidFOrD(char *flagString);
int		findDash(char *flagString, is_set *flags);
void	checkExists(char *flagString, t_ls *data, is_set *flags);
void	checkExists1(char *flagString, t_ls *data);
void	checkExists2(char *flagString, t_ls *data);
int		argCheck(int ac, char **av, is_set *flags, t_ls *data);
int		doubleDash(int ac, char *flagString);
// void	setPriority(is_set *flags);
void	illegalOption(char *flagString);
void	printDasha(t_ls *data);
void	printDashr(t_ls *data);
void	printDasht(t_ls *data);
void	printDashl(t_ls *data, is_set *flags);
void	printBasic(t_ls *data);
void	listDel(t_ls *data);
is_set	*create_flag_space(void);
// t_ls	*store_recursive(char *path);

#endif