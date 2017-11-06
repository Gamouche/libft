#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	char	*strtrim;
	size_t	index;

	index = 0;
	while (*s == ' ' || *s == ',' || *s == '\t' || *s == '\n')
		++s;
	while (s[index] != ' ' && s[index] != ',' && s[index] != '\t'
	&& s[index] != '\n' && s[index] != '\0')
		++index;
	strtrim = (char *)malloc( sizeof(char) * (index + 1) );
	if (strtrim == NULL)
		return (NULL);
	index = 0;
	while (*s != ' ' && *s != ',' && *s != '\t' && *s != '\n' && *s != '\0')
	{
		strtrim[index] = *s;
		++s;
		++index;
	}
	strtrim[index] = '\0';
	return (strtrim);
}