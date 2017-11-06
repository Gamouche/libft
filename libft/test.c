#ifdef TESTGAM

#include <string.h>
#include <stdio.h>
#include <limits.h>
#include "libft.h"
#include <ctype.h>


int		main(void)
{
	for (int c = -15 ; c < 256 ; ++c)
	{
		printf("toupper = %d\n", toupper(c) );
		printf("ft_toupper = %d\n", ft_toupper(c) );
		printf("\n");
	}

	return (0);
}

#endif