#include <stdlib.h>
//#include <stdio.h>
static size_t	get_nb_str(const char *s, char c)
{
	size_t	nb_str;

	nb_str = 0;
	while (*s != '\0')
	{
		while (*s == c)
			++s;
		if (*s != '\0')
			++nb_str;
		while (*s != c && *s != '\0')
			++s;
	}
	return (nb_str);
}

static void		alloc_the_str(char **strsplit, const char *s, char c)
{
	size_t	index;
	size_t	nb_ch;

	index = 0;
	while (*s != '\0')
	{
		while (*s == c)
			++s;
		nb_ch = 0;
		while (*s != c && *s != '\0')
		{
			++s;
			++nb_ch;
		}
		if (nb_ch != 0)
		{
			strsplit[index] = (char *)malloc( sizeof(char) * (nb_ch + 1) ); //printf("alloc str de %zu ch (index = %zu\n", nb_ch, index);
			++index;
		}
	}
}

static void		fill_strsplit(char **strsplit, const char *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (*s != '\0')
	{
		while (*s == c)
			++s;
		j = 0;
		while (*s != c && *s != '\0')
		{
			strsplit[i][j] = *s;
			++j;
			++s;
		}
		if (j > 0)
			strsplit[i][j] = '\0';
		++i;
	}
}

/*

void	lol(char **s)
{
	while (*s != NULL)
	{
		printf("\"%s\"\n", *s);
		++s;
	}

	printf("NULL\n\n");
}

*/

char	**ft_strsplit(char const *s, char c)
{														//printf("APPEL\n");
	char	**strsplit;
	size_t	nb_str;

	nb_str = get_nb_str(s, c);							//printf("nb_str = %zu\n", nb_str);
	strsplit = (char **)malloc( sizeof(char * ) * (nb_str + 1) );
	strsplit[nb_str] = NULL;
	alloc_the_str(strsplit, s, c);
	fill_strsplit(strsplit, s, c);				//printf("\n");  lol(strsplit);
	return (strsplit);
}