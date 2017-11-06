#include <stdlib.h>
#include <stdio.h> // A ENLEVER

static size_t	get_size_alloc(int n)
{
	size_t			size_alloc;
	unsigned int	u;

	if (n == 0)
		return (1);
	size_alloc = (n < 0) ? (1) : (0);
	u = (n < 0) ? ((unsigned int)-n) : ((unsigned int)n);
	while (u > 0)
	{
		u = u / 10;
		++size_alloc;
	}
	return (size_alloc);
}

static void		fill_str(char *str, int n, size_t size_alloc)
{
	unsigned int	u;

	str[size_alloc] = '\0';
	if (n == 0)
	{
		*str = '0';
		return ;
	}
	u = (n < 0) ? ((unsigned int)-n) : ((unsigned int)n);
	while (u > 0)
	{
		--size_alloc;
		str[size_alloc] = u % 10 + '0'; //printf("ON MET \'%c\' dans l'index %zu\n", u % 10 + '0', size_alloc);
		u = u / 10;
	}
	if (n < 0)
		*str = '-';
}

char	*xft_itoa(int n)
{
	char	*str;
	size_t	size_alloc;

	size_alloc = get_size_alloc(n);						//printf("n = %d et size_alloc = %zu\n", n, size_alloc);
	str = (char *)malloc(sizeof(char) * (size_alloc + 1));
	if (str == NULL)
		return (NULL);
	fill_str(str, n, size_alloc);			//printf("RESULT = \"%s\"\n", str);
	return (str);
}

char		*ft_itoa(int n)
{
	int				size_str;
	char			*str;
	unsigned int	n2;

	n2 = (n < 0) ? (unsigned int)-n : (unsigned int)n;
	size_str = (n < 0) ? 2 : 1;
	while ((n2 /= 10))
		size_str++;
	if (!(str = (char*)malloc(sizeof(*str) * (size_str + 1))))
		return (0);
	n2 = (!(str[size_str] = 0) && n < 0) ? (unsigned int)-n : (unsigned int)n;
	while (--size_str >= 0)
		n2 /= ((str[size_str] = n2 % 10 + '0')) ? 10 : 10;
	return ((str[0] = (n < 0) ? '-' : str[0]) ? str : str);
}