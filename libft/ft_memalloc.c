#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
		return (NULL);
	while (--size > 0)
		((char *)ptr)[size] = 0;
	((char *)ptr)[0] = 0;
	return (ptr);
}