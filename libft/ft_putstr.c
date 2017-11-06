#include <unistd.h>

#include "libft.h"

void	ft_putstr(const char *s)
{
	write(STDOUT_FILENO, s, ft_strlen(s));
}