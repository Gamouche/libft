#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new_str;
	size_t			s_len;
	unsigned int	i;

	s_len = 0;
	while (s[s_len] != '\0')
		++s_len;
	new_str = (char *) malloc( sizeof(char) * (s_len + 1) );
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		new_str[i] = (*f)(i, s[i]);
		++i;
	}
	new_str[i] = '\0';
	return (new_str);
}