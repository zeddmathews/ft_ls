#include "./includes/libft.h"

char	*ft_strjoinmult(char *s1, char *s2, char *s3)
{
	s1 = ft_strjoin(s1, s3);
	return(ft_strjoin(s1, s2));
}
