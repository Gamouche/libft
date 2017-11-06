#include <stdlib.h>

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	while (*s1 == *s2 && *s1 != '\0' && n > 0)
	{
		++s1;
		++s2;
		--n;
	}
	return ( (n == 0 || *s1 == *s2) ? (1) : (0) );
}