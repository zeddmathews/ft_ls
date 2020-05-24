#include "../includes/ft_ls.h"

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