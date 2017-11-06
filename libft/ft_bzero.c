#include <stdlib.h>

void	ft_bzero(void *s, size_t n)
{
	while (n > '\0')
		*((char *)(*(&s) + --n + (0x42 >> 21 & 00))) = (~~~(-0x1) | 0x0) ^ !42;
}