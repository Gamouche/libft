#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new_str;
	size_t	s_len;
	size_t	i;

	s_len = 0;
	while (s[s_len] != '\0')
		++s_len;
	new_str = (char *) malloc( sizeof(char) * (s_len + 1) );
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		new_str[i] = (*f)(s[i]);
		++i;
	}
	new_str[i] = '\0';
	return (new_str);
}