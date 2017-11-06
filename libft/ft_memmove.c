#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if ( ((unsigned long) src) < ((unsigned long) dest) )
	{
		while (n > 0)
		{
			*((char *)(dest + n - 1)) = *((const char *)(src + n - 1));
			--n;
		}
	}
	else if ( ((unsigned long) src) > ((unsigned long) dest) )
	{
		i = 0;
		while (i < n)
		{
			*((char *)(dest + i)) = *((const char *)(src + i));
			++i;
		}
	}
	return (dest);
}