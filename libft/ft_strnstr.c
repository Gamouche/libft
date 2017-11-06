#include <stdlib.h>

#include <string.h>

#include <stdio.h>	// A ENLEVER /////////////////////////////

char *xstrnstr(const char *s, const char *find, size_t slen)
{
	char c, sc;
	size_t len;

	if ((c = *find++) != '\0')
	{
		len = strlen(find);
		do {
			do
			{
				if (slen-- < 1 || (sc = *s++) == '\0')
					return NULL;
			} while (sc != c);

			if (len > slen)
				return NULL;

		} while ( strncmp(s, find, len) != 0 );

		s--;
	}

	return ((char *)s);
}

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (*s2 == '\0')
		return ((char *)s1);
	while (*s1 != 0 && n > 0)
	{
		i = 0;
		while (s1[i] == s2[i] && n - i > 0)
		{
			++i;
			if (s2[i] == '\0')
				return ((char *)s1);
		}
		++s1;
		--n;
	} 
	return (NULL);
}