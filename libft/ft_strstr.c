#include <stdlib.h>

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t	i;

	if (*s2 == '\0')
		return ((char *)s1);
	while (*s1 != 0)
	{
		i = 0;
		while (s1[i] == s2[i])
		{
			++i;
			if (s2[i] == '\0')
				return ((char *)s1);
		}
		++s1;
	}
	return (NULL);
}
