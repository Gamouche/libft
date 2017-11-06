#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	char			tab[50]; // taille arbitraire
	unsigned short	index;
	unsigned int	u;

	index = 49;
	u = (n < 0) ? ((unsigned int)-n) : ((unsigned int)n);
	while (u > 0)
	{
		tab[index] = u % 10 + '0';
		--index;
		u = u / 10;
	}
	if (n < 0)
	{
		tab[index] = '-';
		--index;
	}
	else if (n == 0)
	{
		tab[index] = '0';
		--index;
	}
	write(fd, tab + index + 1, 49 - index);
}