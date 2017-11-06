#include <stdlib.h>

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*strdup;

	if ((strdup = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))) == NULL)
		return (NULL);
	return (ft_memcpy(strdup, s, ft_strlen(s) + 1));
}
