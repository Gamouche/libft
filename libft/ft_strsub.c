#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*strsub;
	size_t	index;

	strsub = (char *)malloc( sizeof(char) * (len + 1) );
	if (strsub == NULL)
		return (NULL);
	index = 0;
	while (index < len)
	{
		strsub[index] = s[start + index];
		++index;
	}
	strsub[index] = '\0';	
	return (strsub);
}