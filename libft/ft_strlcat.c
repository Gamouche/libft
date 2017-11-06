#include <stdlib.h>

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;

	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	if (size <= dest_len)
		return (src_len + size);
 	size = size - dest_len - 1;
	while (*dest)
		dest++;
	while (*src != '\0' && size > 0)
	{
		*dest = *src;
		++dest;
		++src;
		--size;
	}
	*dest = '\0';
	return (src_len + dest_len);
}