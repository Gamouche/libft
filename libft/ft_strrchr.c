#include <stdlib.h>

char	*ft_strrchr(const char *s, int c)
{
	const char	*begin;

	begin = s;
	while (*s != '\0')
		++s;
	while (*s != c)
	{
		if (s == begin)
			return (NULL);
		--s;
	}
	return ((char *)s);
}