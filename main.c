#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdint.h>
#include <ctype.h>

//#include "../mongit/libft.h"
#include "libft.h"

#define TMP_FILE "jesuisunfichiertemporaire.txt"

// other functions
void	do_at_exit(void);

// part 2
void	test_memalloc(void);
void	test_memdel(void);
void 	test_strnew(void);
void	test_strdel(void);
void	test_strclr(void);
void	test_striter(void);
void	test_striteri(void);
void	test_strmap(void);
void	test_strmapi(void);
void	test_strequ(void);
void	test_strnequ(void);
void	test_strsub(void);
void	test_strjoin(void);
void	test_strtrim(void);
void	test_strsplit(void);
void	test_itoa(void);
void	test_putchar(void);
void	test_putstr(void);
void	test_putendl(void);
void	test_putnbr(void);
void	test_putchar_fd(void);
void	test_putstr_fd(void);
void	test_putendl_fd(void);
void	test_putnbr_fd(void);

// part 1
void	test_memset(void);
void	test_bzero(void);
void	test_memcpy(void);
void	test_memccpy(void);
void	test_memmove(void);
void	test_memchr(void);
void	test_memcmp(void);
void 	test_strlen(void);
void	test_strdup(void);
void	test_strcpy(void);
void	test_strncpy(void);
void	test_strcat(void);
void	test_strncat(void);
void	test_strlcat(void);
void	test_strchr(void);
void	test_strrchr(void);
void	test_strstr(void);
void	test_strnstr(void);
void	test_strcmp(void);
void 	test_strncmp(void);
void 	test_atoi(void);
void 	test_isalpha(void);
void 	test_isdigit(void);
void 	test_isalnum(void);
void 	test_isascii(void);
void 	test_isprint(void);
void 	test_toupper(void);
void 	test_tolower(void);

// bonus

void	test_lstnew(void);
void	test_lstdelone(void);
void	test_lstdel(void);
void	test_lstmap(void);


void	do_at_exit(void)
{
	remove(TMP_FILE);
}

// BEG LOL

	void	my_toupper_lol(char *ptr);
	void	my_toupper_lol_2(unsigned int index, char *ptr);
	char 	my_toupper_lol_3(char c);
	char	my_toupper_lol_4(unsigned int u, char c);
	void	lst_del_lol(void *ptr, size_t size);

	void	my_toupper_lol(char *ptr)
	{
		if (*ptr >= 'a' && *ptr <= 'z')
			*ptr = *ptr - 'a' + 'A';
	}

	void	my_toupper_lol_2(unsigned int index, char *ptr)
	{
		if ( (index & 1) == 0 )
		{
			if (*ptr >= 'a' && *ptr <= 'z')
				*ptr = *ptr - 'a' + 'A';
		}
	}

	char 	my_toupper_lol_3(char c)
	{
		if (c >= 'a' && c <= 'z')
			c = c - 'a' + 'A';
		return (c);
	}

	char	my_toupper_lol_4(unsigned int index, char c)
	{
		if ( c >= 'a' && c <= 'z' && (index & 1) == 0 )
			c = c - 'a' + 'A';
		return (c);
	}

	void	lst_del_lol(void *ptr, size_t size)
	{
		(void) size;
		free(ptr);
	}

	t_list	*funclstmap(t_list *ptr)
	{
		t_list *new =  ft_lstnew(ptr->content, ptr->content_size);
		*(int *)((*new).content) = (*((int *)((*ptr).content))) + 1;
		return (new);
	}

// END LOL

void	test_memalloc(void)
{
	char	*ptr;

	ptr = ft_memalloc(42);

	if (ptr == NULL)
	{
		puts("MEMALLOC FAIL 1");
		return ;
	}

	for (size_t i = 0 ; i < 42 ; ++i)
	{
		if (ptr[i] != 0)
		{
			puts("MEMALLOC FAIL 2");
			free(ptr);
			return ;
		}
	}

	free(ptr);
	puts("MEMALLOC OK");
}

void	test_memdel(void)
{
	void	*ptr;

	ptr = malloc(1);
	ft_memdel(&ptr);
	if (ptr != NULL)
	{
		puts("MEMDEL FAIL 1");
		return ;
	}

	puts("MEMDEL OK");
}

void	test_strnew(void)
{
	char	*str;

	str = ft_strnew(10);
	if (str == NULL)
	{
		puts("STRNEW FAIL 1");
		return ;
	}

	for (size_t i = 0 ; i < 10 + 1 ; ++i)
	{
		if (str[i] != 0)
		{
			puts("STRNEW FAIL 2");
			free(str);
			return ;
		}
	}

	free(str);
	puts("STRNEW OK");
}

void	test_strdel(void)
{
	char	*str;

	str = malloc( sizeof(char) * 10 );
	ft_strdel(&str);

	if (str != NULL)
	{
		puts("STRDEL FAIL 1");
		return ;
	}

	puts("STRDEL OK");
}

void	test_strclr(void)
{
	char	*str;

	str = calloc( 8, sizeof(char) );
	str[0] = '\0';
	strncat(str, "bonjour", 7);

	ft_strclr(str);
	for (size_t i = 0 ; i < 8 ; ++i)
	{
		if (str[i] != 0)
		{
			puts("STRCLR FAIL 1");
			free(str);
			return ;
		}
	}

	free(str);
	puts("STRCLR OK");
}

void	test_striter(void)
{
	char	tab[] = "bonjour";

	ft_striter( tab, & my_toupper_lol );

	if ( strcmp(tab, "BONJOUR") != 0 )
	{
		puts("STRITER FAIL 1");
		return ;
	}

	printf("STRITER OK\n");
}

void test_striteri(void)
{
	char	tab[] = "bonjour";

	ft_striteri( tab, & my_toupper_lol_2 );

	if ( strcmp(tab, "BoNjOuR") != 0 )
	{
		puts("STRITERI FAIL 1");
		return ;
	}

	printf("STRITERI OK\n");
}

void	test_strmap(void)
{
	char	tab[] = "bonjour";
	char	*result;

	result = ft_strmap( tab, & my_toupper_lol_3 );

	if (result == NULL)
	{
		puts("STRMAP FAIL 1");
		return ;
	}

	if ( strcmp(result, "BONJOUR") != 0 )
	{
		puts("STRMAP FAIL 2");
		free(result);
		return ;
	}

	free(result);
	puts("STRMAP OK");
}

void	test_strmapi(void)
{
	char	tab[] = "bonjour";
	char	*result;

	result = ft_strmapi( tab, & my_toupper_lol_4 );

	if (result == NULL)
	{
		puts("STRMAPI FAIL 1");
		return ;
	}

	if ( strcmp(result, "BoNjOuR") != 0 )
	{
		puts("STRMAPI FAIL 2");
		free(result);
		return ;
	}

	free(result);
	puts("STRMAPI OK");
}

void	test_strequ(void)
{
	if ( ft_strequ("", "") == 0
	|| ft_strequ("bonjour", "bonjour") == 0 
	|| ft_strequ("bonjour", "bonjoura") == 1 
	|| ft_strequ("bonjour", "") == 1
	|| ft_strequ("bonjour", "bonjOur") == 1
	|| ft_strequ("", "bonjour") == 1 )
	{
		puts("STREQU FAIL 1");
		return ;
	}

	puts("STREQU OK");
}

void	test_strnequ(void)
{
	if ( ft_strnequ("", "", 5) == 0
	|| ft_strnequ("bonjour", "bonjour", 7) == 0 
	|| ft_strnequ("bonjour", "bonjoura", 7) == 0 
	|| ft_strnequ("bonjour", "", 0) == 0
	|| ft_strnequ("bonjour", "bonjOur", 7) == 1
	|| ft_strnequ("", "bonjour", 10) == 1 
	|| ft_strnequ("bonjour", "bonjoura", 8) == 1 
	|| ft_strnequ("bonjourz", "bonjoura", 8) == 1 ) 
	{
		puts("STRNEQU FAIL 1");
		return ;
	}

	puts("STRNEQU OK");
}

void	test_strsub(void)
{
	char	*res;
	char	*res2;
	char	*res3;
	char	*res4;

	res = ft_strsub("je suis une chaine", 8, 5);
	res2 = ft_strsub("je suis une chaine", 0, 10);
	res3 = ft_strsub("je suis une chaine", 7, 7);
	res4 = ft_strsub("je suis une chaine", 3, 1);

	if (res == NULL || res2 == NULL || res3 == NULL || res4 == NULL)
	{
		puts("STRSUB FAIL 1");
		free(res); free(res2); free(res3); free(res4);
		return ;
	}

	if ( strcmp(res, "une c") != 0
	|| strcmp(res2, "je suis un") != 0
	|| strcmp(res3, " une ch") != 0
	|| strcmp(res4, "s") != 0 )
	{
		puts("STRSUB FAIL 2");
		free(res); free(res2); free(res3); free(res4);
		return ;
	}

	free(res); free(res2); free(res3); free(res4);
	puts("STRSUB OK");
}

void	test_strjoin(void)
{
	char	*res, *res2, *res3, *res4;

	res = ft_strjoin("lol", "lol");
	res2 = ft_strjoin("lol", "");
	res3 = ft_strjoin("", "");
	res4 = ft_strjoin("", "lol");

	if (res == NULL || res2 == NULL || res3 == NULL || res4 == NULL)
	{
		puts("STRJOIN FAIL 1");
		free(res); free(res2); free(res3); free(res4);
		return ;
	}

	if ( strcmp(res, "lollol") != 0
	|| strcmp(res2, "lol") != 0
	|| strcmp(res3, "") != 0
	|| strcmp(res4, "lol") != 0 )
	{
		puts("STRJOIN FAIL 2");
		free(res); free(res2); free(res3); free(res4);
		return ;
	}

	free(res); free(res2); free(res3); free(res4);
	puts("STRJOIN OK");
}

void	test_strtrim(void)
{
	char	*res, *res2, *res3, *res4, *res5, *res6, *res7;

	res = ft_strtrim("bonjour");
	res2 = ft_strtrim("  ,bonjour");
	res3 = ft_strtrim("bonjour\t,");
	res4 = ft_strtrim("  bonjour\n");
	res5 = ft_strtrim("");
	res6 = ft_strtrim(",");
	res7 = ft_strtrim("    ");

	if (res == NULL || res2 == NULL || res3 == NULL || res4 == NULL || res5 == NULL || res6 == NULL || res7 == NULL)
	{
		puts("STRTRIM FAIL 1");
		free(res); free(res2); free(res3); free(res4); free(res5); free(res6); free(res7);
		return ;
	}

	if ( strcmp(res, "bonjour") != 0
	|| strcmp(res2, ",bonjour") != 0
	|| strcmp(res3, "bonjour\t,") != 0
	|| strcmp(res4, "bonjour") != 0
	|| strcmp(res5, "") != 0
	|| strcmp(res6, ",") != 0
	|| strcmp(res7, "") != 0 )
	{
		puts("STRTRIM FAIL 2");
		free(res); free(res2); free(res3); free(res4); free(res5); free(res6); free(res7);
		return ;
	}

	free(res); free(res2); free(res3); free(res4); free(res5); free(res6); free(res7);
	puts("STRTRIM OK");
}

void	test_strsplit(void)
{
	char	**res, **res2, **res3, **res4;
	char	res_test[3][10] = { "salut", "les", "etudiants" };
	char	res2_test[1][20] = { "salut les etudiants" };
	char 	res3_test[3][11] = { "sal", "t les", " etudiants" };
	//char	res4_test[1][1] = { "" };
	size_t	nb_str;

	res = ft_strsplit("*salut*les***etudiants*", '*');
	res2 = ft_strsplit("salut les etudiants", '*');
	res3 = ft_strsplit("sal*t les* etudiants", '*');
	res4 = ft_strsplit("", '*');

	if (res == NULL || res2 == NULL || res3 == NULL || res4 == NULL)
	{
		puts("STRSPLIT FAIL 1 -- there can be memory leaks from ft_strsplit(), "
		"this test does not try to free() them all");
		free(res); free(res2); free(res3); free(res4);
		return ;
	}

	nb_str = 0;
	while (res[nb_str] != NULL)
		++nb_str;
	if (nb_str != 3)
	{
		puts("STRSPLIT FAIL 2 -- there can be memory leaks from ft_strsplit(), "
		"this test does not try to free() them all");
		free(res); free(res2); free(res3); free(res4);
		return ;
	}

	for (size_t i = 0 ; res[i] != NULL ; ++i)
	{
		if ( strcmp(res[i], res_test[i]) != 0 )
		{
			puts("STRSPLIT FAIL 3 -- there can be memory leaks from ft_strsplit(), "
			"this test does not try to free() them all");
			free(res); free(res2); free(res3); free(res4);
			return ;
		}
		free(res[i]);
	}
	free(res);

	nb_str = 0;
	while (res2[nb_str] != NULL)
		++nb_str;
	if (nb_str != 1)
	{
		puts("STRSPLIT FAIL 4 -- there can be memory leaks from ft_strsplit(), "
		"this test does not try to free() them all");
		free(res); free(res2); free(res3); free(res4);
		return ;
	}

	for (size_t i = 0 ; res2[i] != NULL ; ++i)
	{
		if ( strcmp(res2[i], res2_test[i]) != 0 )
		{
			puts("STRSPLIT FAIL 5 -- there can be memory leaks from ft_strsplit(), "
			"this test does not try to free() them all");
			free(res); free(res2); free(res3); free(res4);
			return ;
		}
		free(res2[i]);
	}
	free(res2);

	nb_str = 0;
	while (res3[nb_str] != NULL)
		++nb_str;
	if (nb_str != 3)
	{
		puts("STRSPLIT FAIL 6 -- there can be memory leaks from ft_strsplit(), "
		"this test does not try to free() them all");
		free(res); free(res2); free(res3); free(res4);
		return ;
	}

	for (size_t i = 0 ; res3[i] != NULL ; ++i)
	{
		if ( strcmp(res3[i], res3_test[i]) != 0 )
		{
			puts("STRSPLIT FAIL 7 -- there can be memory leaks from ft_strsplit(), "
			"this test does not try to free() them all");
			free(res); free(res2); free(res3); free(res4);
			return ;
		}
		free(res3[i]);
	}
	free(res3);

	nb_str = 0;
	while (res4[nb_str] != NULL)
		++nb_str;
	if (nb_str != 0)
	{
		puts("STRSPLIT FAIL 8 -- there can be memory leaks from ft_strsplit(), "
		"this test does not try to free() them all");
		free(res); free(res2); free(res3); free(res4);
		return ;
	}

	free(res4);
	puts("STRSPLIT OK");
}

void	test_itoa(void)
{
	char	*res, *res2, *res3, *res4, *res5, *res6, *res7;

	res = ft_itoa(-10);
	res2 = ft_itoa(0);
	res3 = ft_itoa(10);
	res4 = ft_itoa(123456789);
	res5 = ft_itoa(-123456789);
	res6 = ft_itoa(-2147483648);
	res7 = ft_itoa(2147483647);

	if (res == NULL || res2 == NULL || res3 == NULL || res4 == NULL || res5 == NULL || res6 == NULL || res7 == NULL)
	{
		puts("ITOA FAIL 1");
		free(res); free(res2); free(res3); free(res4); free(res5); free(res6); free(res7);
		return ;
	}

	if ( strcmp(res, "-10") != 0
	|| strcmp(res2, "0") != 0
	|| strcmp(res3, "10") != 0
	|| strcmp(res4, "123456789") != 0
	|| strcmp(res5, "-123456789") != 0
	|| strcmp(res6, "-2147483648") != 0
	|| strcmp(res7, "2147483647") != 0 )
	{
		puts("ITOA FAIL 2");
		free(res); free(res2); free(res3); free(res4); free(res5); free(res6); free(res7);
		return ;
	}

	free(res); free(res2); free(res3); free(res4); free(res5); free(res6); free(res7);
	puts("ITOA OK");
}

void	test_putchar(void)
{
	int 	saved_stdout_fd;
	int 	tmp_stdout_fd;
	char	tab[10] = {0};
	ssize_t	read_ret;

	if ( (tmp_stdout_fd = open(TMP_FILE, O_CREAT | O_RDWR, 00777)) == -1 )
	{
		perror("perror(), open() failed");
		exit(EXIT_FAILURE);
	}

	if ( (saved_stdout_fd = dup(STDOUT_FILENO)) == -1 )
	{
		perror("perror(), dup() failed");
		exit(EXIT_FAILURE);
	}

	if ( dup2(tmp_stdout_fd, STDOUT_FILENO) == -1 )
	{
		perror("perror(), dup2() failed");
		exit(EXIT_FAILURE);
	}

	ft_putchar('A');
	ft_putchar('\n');
	ft_putchar('B');

	lseek(STDOUT_FILENO, 0, SEEK_SET);
	
	if ( (read_ret = read(STDOUT_FILENO, tab, 5)) == -1 )
	{
		perror("perror(), read() failed");
		exit(EXIT_FAILURE);
	}

	if ( dup2(saved_stdout_fd, STDOUT_FILENO) == -1 )
	{
		perror("perror(), dup2() failed");
		exit(EXIT_FAILURE);
	}

	if (read_ret == 0)
	{
		puts("PUTCHAR FAIL 1");
		return ;
	}

	if ( strcmp(tab, "A\nB") != 0 )
	{
		puts("PUTCHAR FAIL 2");
		return ;
	}

	close(saved_stdout_fd);
	close(tmp_stdout_fd);
	remove(TMP_FILE);

	puts("PUTCHAR OK");
}

void	test_putstr(void)
{
	int 	saved_stdout_fd;
	int 	tmp_stdout_fd;
	char	tab[100] = {0};
	ssize_t	read_ret;

	if ( (tmp_stdout_fd = open(TMP_FILE, O_CREAT | O_RDWR, 00777)) == -1 )
	{
		perror("perror(), open() failed");
		exit(EXIT_FAILURE);
	}

	if ( (saved_stdout_fd = dup(STDOUT_FILENO)) == -1 )
	{
		perror("perror(), dup() failed");
		exit(EXIT_FAILURE);
	}

	if ( dup2(tmp_stdout_fd, STDOUT_FILENO) == -1 )
	{
		perror("perror(), dup2() failed");
		exit(EXIT_FAILURE);
	}

	ft_putstr("string123\nlol");

	lseek(STDOUT_FILENO, 0, SEEK_SET);
	
	if ( (read_ret = read(STDOUT_FILENO, tab, 25)) == -1 )
	{
		perror("perror(), read() failed");
		exit(EXIT_FAILURE);
	}

	if ( dup2(saved_stdout_fd, STDOUT_FILENO) == -1 )
	{
		perror("perror(), dup2() failed");
		exit(EXIT_FAILURE);
	}

	if (read_ret == 0)
	{
		puts("PUTSTR FAIL 1");
		return ;
	}

	if ( strcmp(tab, "string123\nlol") != 0 )
	{
		puts("PUTSTR FAIL 2");
		return ;
	}

	close(saved_stdout_fd);
	close(tmp_stdout_fd);
	remove(TMP_FILE);

	puts("PUTSTR OK");
}

void	test_putendl(void)
{
	int 	saved_stdout_fd;
	int 	tmp_stdout_fd;
	char	tab[100] = {0};
	ssize_t	read_ret;

	if ( (tmp_stdout_fd = open(TMP_FILE, O_CREAT | O_RDWR, 00777)) == -1 )
	{
		perror("perror(), open() failed");
		exit(EXIT_FAILURE);
	}

	if ( (saved_stdout_fd = dup(STDOUT_FILENO)) == -1 )
	{
		perror("perror(), dup() failed");
		exit(EXIT_FAILURE);
	}

	if ( dup2(tmp_stdout_fd, STDOUT_FILENO) == -1 )
	{
		perror("perror(), dup2() failed");
		exit(EXIT_FAILURE);
	}

	ft_putendl("string123\"\nlol");

	lseek(STDOUT_FILENO, 0, SEEK_SET);
	
	if ( (read_ret = read(STDOUT_FILENO, tab, 25)) == -1 )
	{
		perror("perror(), read() failed");
		exit(EXIT_FAILURE);
	}

	if ( dup2(saved_stdout_fd, STDOUT_FILENO) == -1 )
	{
		perror("perror(), dup2() failed");
		exit(EXIT_FAILURE);
	}

	if (read_ret == 0)
	{
		puts("PUTENDL FAIL 1");
		return ;
	}

	if ( strcmp(tab, "string123\"\nlol\n") != 0 )
	{
		puts("PUTENDL FAIL 2");
		return ;
	}

	close(saved_stdout_fd);
	close(tmp_stdout_fd);
	remove(TMP_FILE);

	puts("PUTENDL OK");
}

void	test_putnbr(void)
{
	int 	saved_stdout_fd;
	int 	tmp_stdout_fd;
	char	tab[100] = {0};
	ssize_t	read_ret;
	char	expected_output[100] = {0};

	if ( (tmp_stdout_fd = open(TMP_FILE, O_CREAT | O_RDWR, 00777)) == -1 )
	{
		perror("perror(), open() failed");
		exit(EXIT_FAILURE);
	}

	if ( (saved_stdout_fd = dup(STDOUT_FILENO)) == -1 )
	{
		perror("perror(), dup() failed");
		exit(EXIT_FAILURE);
	}

	if ( dup2(tmp_stdout_fd, STDOUT_FILENO) == -1 )
	{
		perror("perror(), dup2() failed");
		exit(EXIT_FAILURE);
	}

	ft_putnbr(INT_MIN);
	ft_putnbr(-12345);
	ft_putnbr(-10);
	ft_putnbr(0);
	ft_putnbr(10);
	ft_putnbr(12345);
	ft_putnbr(INT_MAX);

	sprintf(expected_output, "%d%d%d%d%d%d%d", INT_MIN, -12345, -10, 0, 10, 12345, INT_MAX);

	lseek(STDOUT_FILENO, 0, SEEK_SET);
	
	if ( (read_ret = read(STDOUT_FILENO, tab, 80)) == -1 )
	{
		perror("perror(), read() failed");
		exit(EXIT_FAILURE);
	}

	if ( dup2(saved_stdout_fd, STDOUT_FILENO) == -1 )
	{
		perror("perror(), dup2() failed");
		exit(EXIT_FAILURE);
	}

	if (read_ret == 0)
	{
		puts("PUTNBR FAIL 1");
		return ;
	}

	if ( strcmp(tab, expected_output) != 0 )
	{
		puts("PUTNBR FAIL 2");
		return ;
	}

	close(saved_stdout_fd);
	close(tmp_stdout_fd);
	remove(TMP_FILE);

	puts("PUTNBR OK");
}

void	test_putchar_fd(void)
{
	int 	fd;
	char	tab[10] = "";
	ssize_t	read_ret;

	if ( (fd = open(TMP_FILE, O_CREAT | O_RDWR, 00777)) == -1 )
	{
		perror("perror() open() failed, exit program");
		exit(EXIT_FAILURE);
	}

	ft_putchar_fd('Z', fd);
	lseek(fd, 0, SEEK_SET);

	if ( (read_ret = read(fd, tab, 1)) == -1 )
	{
		perror("perror() read() failed, exit program");
		close(fd);
		exit(EXIT_FAILURE);
	}

	if (read_ret == 0)
	{
		puts("PUTCHAR_FD FAIL 1");
		close(fd);
		return ;
	}

	tab[read_ret] = '\0';

	if ( strlen(tab) != 1 || tab[0] != 'Z' )
	{
		puts("PUTCHAR_FD FAIL 2");
		close(fd);
		return ;
	}

	if ( (read_ret = read(fd, tab, 1)) == -1 )
	{
		perror("perror() read() failed, exit program");
		close(fd);
		exit(EXIT_FAILURE);
	}

	if (read_ret > 0)
	{
		puts("PUTCHAR_FD FAIL 3");
		close(fd);
		return ;
	}

	close(fd);
	remove(TMP_FILE);
	puts("PUTCHAR_FD OK");
}

void	test_putstr_fd(void)
{
	int 	fd;
	char	tab[100] = "";
	ssize_t	read_ret;

	if ( (fd = open(TMP_FILE, O_CREAT | O_RDWR, 00777)) == -1 )
	{
		perror("perror() open() failed, exit program");
		exit(EXIT_FAILURE);
	}

	ft_putstr_fd("string123", fd);
	lseek(fd, 0, SEEK_SET);

	if ( (read_ret = read(fd, tab, 99)) == -1 )
	{
		perror("perror() read() failed, exit program");
		close(fd);
		exit(EXIT_FAILURE);
	}

	if (read_ret == 0)
	{
		puts("PUTSTR_FD FAIL 1");
		close(fd);
		return ;
	}

	tab[read_ret] = '\0';

	if ( strlen(tab) != 9 || strcmp(tab, "string123") != 0 )
	{
		puts("PUTSTR_FD FAIL 2");
		close(fd);
		return ;
	}

	if ( (read_ret = read(fd, tab, 1)) == -1 )
	{
		perror("perror() read() failed, exit program");
		close(fd);
		exit(EXIT_FAILURE);
	}

	if (read_ret > 0)
	{
		puts("PUTSTR_FD FAIL 3");
		close(fd);
		return ;
	}

	close(fd);
	remove(TMP_FILE);
	puts("PUTSTR_FD OK");
}

void	test_putendl_fd(void)
{
	int 	fd;
	char	tab[100] = "";
	ssize_t	read_ret;

	if ( (fd = open(TMP_FILE, O_CREAT | O_RDWR, 00777)) == -1 )
	{
		perror("perror() open() failed, exit program");
		exit(EXIT_FAILURE);
	}

	ft_putendl_fd("string123", fd);
	lseek(fd, 0, SEEK_SET);

	if ( (read_ret = read(fd, tab, 10)) == -1 )
	{
		perror("perror() read() failed, exit program");
		close(fd);
		exit(EXIT_FAILURE);
	}

	if (read_ret == 0)
	{
		puts("PUTENDL_FD FAIL 1");
		close(fd);
		return ;
	}

	tab[read_ret] = '\0';

	if ( strlen(tab) != 10 || strcmp(tab, "string123\n") != 0 )
	{
		puts("PUTENDL_FD FAIL 2");
		close(fd);
		return ;
	}

	if ( (read_ret = read(fd, tab, 1)) == -1 )
	{
		perror("perror() read() failed, exit program");
		close(fd);
		exit(EXIT_FAILURE);
	}

	if (read_ret > 0)
	{
		puts("PUTENDL_FD FAIL 3");
		close(fd);
		return ;
	}

	close(fd);
	remove(TMP_FILE);
	puts("PUTENDL_FD OK");
}

void	test_putnbr_fd(void)
{
	int 	fd;
	char	tab[100] = {0};
	ssize_t	read_ret;
	char	expected_output[100] = {0};

	if ( (fd = open(TMP_FILE, O_CREAT | O_RDWR, 00777)) == -1 )
	{
		perror("perror() open() failed, exit program");
		exit(EXIT_FAILURE);
	}

	ft_putnbr_fd(INT_MIN, fd);
	ft_putnbr_fd(-12345, fd);
	ft_putnbr_fd(-10, fd);
	ft_putnbr_fd(0, fd);
	ft_putnbr_fd(10, fd);
	ft_putnbr_fd(12345, fd);
	ft_putnbr_fd(INT_MAX, fd);

	sprintf(expected_output, "%d%d%d%d%d%d%d", INT_MIN, -12345, -10, 0, 10, 12345, INT_MAX);

	lseek(fd, 0, SEEK_SET);

	if ( (read_ret = read(fd, tab, 80)) == -1 )
	{
		perror("perror() read() failed, exit program");
		close(fd);
		exit(EXIT_FAILURE);
	}

	if (read_ret == 0)
	{
		puts("PUTNBR_FD FAIL 1");
		close(fd);
		return ;
	}

	if ( strcmp(expected_output, tab) != 0 )
	{
		puts("PUTNBR_FD FAIL 2");
		close(fd);
		return ;
	}

	close(fd);
	remove(TMP_FILE);
	puts("PUTNBR_FD OK");
}

void	test_memset(void)
{
	char	tab[] = "bonjour je suis un test";

	if (  ((uintptr_t) ft_memset(tab, 'X', 10)) != ((uintptr_t) tab)  )
	{
		puts("MEMSET FAIL 1");
		return ;
	}

	if ( strcmp(tab, "XXXXXXXXXX suis un test") != 0 )
	{
		puts("MEMSET FAIL 2");
		return ;
	}

	puts("MEMSET OK");
}

void	test_bzero(void)
{
	char	tab[] = "test tset";
	char	expected[] = { '\0', '\0', '\0', '\0', '\0', 't', 's', 'e', 't' };

	ft_bzero(tab, 5);

	for (size_t i = 0; i < 9 ; ++i)
	{
		if (tab[i] != expected[i])
		{
			puts("BZERO FAIL 1");
			return ;
		}
	}

	puts("BZERO OK");
}

void	test_memcpy(void)
{
	char	tab[] = "je suis un test";
	char	dest[ strlen(tab) + 1 ];

	struct s_
	{
		int 	i;
		char	array[40];
	};

	struct s_ st = { 42, "string123" };
	struct s_ st_dest;

	if (   ((uintptr_t) ft_memcpy( dest, tab, strlen(tab) + 1 )) != ((uintptr_t) dest)   )
	{
		puts("MEMCPY FAIL 1");
		return ;
	}

	if ( strcmp(tab, dest) != 0 )
	{
		puts("MEMCPY FAIL 2");
		return ;
	}

	if (   ((uintptr_t) ft_memcpy( &st_dest, &st, sizeof(struct s_) )) != ((uintptr_t) &st_dest)   )
	{
		puts("MEMCPY FAIL 3");
		return ;
	}

	if ( st_dest.i != 42 || strcmp(st_dest.array, st.array) != 0 )
	{
		puts("MEMCPY FAIL 4");
		return ;
	}

	puts("MEMCPY OK");
}

void	test_memccpy(void)
{
	char 	*s1 = "Taj Mahal is a historic monument in India.";
	char 		buffer[61];
	char		*ptr;

	ptr = ft_memccpy(buffer, s1, 'c', strlen(s1));

	if ( ((uintptr_t) ptr )!= ((uintptr_t) (buffer + 23)) )
	{
		puts("MEMCCPY FAIL 1");
		return ;
	}

	*ptr = 0;

	if ( strcmp(buffer, "Taj Mahal is a historic") != 0 )
	{
		puts("MEMCCPY FAIL 2");
		return ;
	}

	memset(buffer, 0, 61);

	ptr = ft_memccpy(buffer, s1, 'z', strlen(s1));

	if (ptr != NULL)
	{
		puts("MEMCCPY FAIL 3");
		return ;
	}

	if ( strcmp(buffer, s1) != 0 )
	{
		puts("MEMCCPY FAIL 4");
		return ;
	}

	puts("MEMCCPY OK");
}

void	test_memmove(void)
{
	char	un[] = "0123456789";
	char	deux[] = "ABCDEFGHIJKL";

	if (  ((uintptr_t) ft_memmove(deux, un, 4)) != ((uintptr_t) deux)  )
	{
		puts("MEMMOVE FAIL 1");
		return ;
	}

	if ( strcmp(un, "0123456789") != 0 || strcmp(deux, "0123EFGHIJKL") != 0 )
	{
		puts("MEMMOVE FAIL 2");
		return ;
	}

	if (  ((uintptr_t) ft_memmove(un + 3, un, 4)) != ((uintptr_t) un + 3)  )
	{
		puts("MEMMOVE FAIL 3");
		return ;
	}

	if ( strcmp(un, "0120123789") != 0 || strcmp(deux, "0123EFGHIJKL") != 0 )
	{
		puts("MEMMOVE FAIL 4");
		return ;
	}

	if (  ((uintptr_t) ft_memmove(deux, deux, 5)) != ((uintptr_t) deux)  )
	{
		puts("MEMMOVE FAIL 5");
		return ;
	}

	if ( strcmp(un, "0120123789") != 0 || strcmp(deux, "0123EFGHIJKL") != 0 )
	{
		puts("MEMMOVE FAIL 6");
		return ;
	}

	if (  ((uintptr_t) ft_memmove(deux, deux + 4, 5)) != ((uintptr_t) deux)  )
	{
		puts("MEMMOVE FAIL 7");
		return ;
	}

	if ( strcmp(un, "0120123789") != 0 || strcmp(deux, "EFGHIFGHIJKL") != 0 )
	{
		puts("MEMMOVE FAIL 8");
		return ;
	}

	if (  ((uintptr_t) ft_memmove(un, deux, 6)) != ((uintptr_t) un)  )
	{
		puts("MEMMOVE FAIL 9");
		return ;
	}

	if ( strcmp(un, "EFGHIF3789") != 0 || strcmp(deux, "EFGHIFGHIJKL") != 0 )
	{
		puts("MEMMOVE FAIL 10");
		return ;
	}

	puts("MEMMOVE OK");
}

void	test_memchr(void)
{
	char	tab[] = "doubidoubidouwap";

	void	*real;
	void	*ft;

	real = memchr( tab, 'a', strlen(tab) );
	ft = ft_memchr( tab, 'a', strlen(tab) );

	if ( (uintptr_t) real != (uintptr_t) ft )
	{
		puts("MEMCHR FAIL 1");
		return ;
	}

	real = memchr( tab, 'p', strlen(tab) );
	ft = ft_memchr( tab, 'p', strlen(tab) );

	if ( (uintptr_t) real != (uintptr_t) ft )
	{
		puts("MEMCHR FAIL 2");
		return ;
	}

	real = memchr( tab, 'z', strlen(tab) );
	ft = ft_memchr( tab, 'z', strlen(tab) );

	if ( (uintptr_t) real != (uintptr_t) ft )
	{
		puts("MEMCHR FAIL 3");
		return ;
	}

	puts("MEMCHR OK");
}

void	test_memcmp(void)
{
	if ( ft_memcmp("bonjour", "bonjour", 7) != 0
	|| ft_memcmp("bonjour", "Bonjour", 0) != 0
	|| ft_memcmp("bonjour", "bonJour", 6) <= 0
	|| ft_memcmp("bonjour", "bonJOur", 2) != 0
	|| ft_memcmp("BONJOUR", "BONJour", 5) >= 0 )
	{
		puts("MEMCMP FAIL 1");
		return ;
	}

	puts("MEMCMP OK");
}

void	test_strlen(void)
{
	if ( ft_strlen("bonjour") != 7 
	|| ft_strlen("") != 0
	|| ft_strlen("carotte\0mdr") != 7
	|| ft_strlen("je suis une chaine bcp trop longue pour etre un exemple decent") != 62 )
	{
		puts("STRLEN FAIL 1");
		return ;
	}

	puts("STRLEN OK");
}

void	test_strdup(void)
{
	char	*res;

	res = ft_strdup("PHILOSOPHIE");
	if ( res == NULL || strcmp("PHILOSOPHIE", res) != 0 )
	{
		puts("STRDUP FAIL 1");
		free(res);
		return ;
	}
	free(res);

	res = ft_strdup("");
	if ( res == NULL || strcmp("", res) != 0 )
	{
		puts("STRDUP FAIL 2");
		free(res);
		return ;
	}
	free(res);

	res = ft_strdup("CORALINE EST CONTENTE HEUREUSEMENT QUE PAPA ETAIT LA\n");
	if ( res == NULL || strcmp("CORALINE EST CONTENTE HEUREUSEMENT QUE PAPA ETAIT LA\n", res) != 0 )
	{
		puts("STRDUP FAIL 3");
		free(res);
		return ;
	}

	free(res);
	puts("STRDUP OK");
}

void	test_strcpy(void)
{
	char	src[100] = "JE SUIS SRC";
	char 	dest[100] = "JE SUIS DEST";

	if ( (((uintptr_t) ft_strcpy(dest, src)) != ((uintptr_t) dest)) || strcmp(dest, src) != 0 )
	{
		puts("STRCPY FAIL 1");
		return ;
	}

	*src = 0x00;
	if ( (((uintptr_t) ft_strcpy(dest, src)) != ((uintptr_t) dest)) || strcmp(dest, src) != 0 )
	{
		puts("STRCPY FAIL 2");
		return ;
	}

	puts("STRCPY OK");
}

void	test_strncpy(void)
{
	char	src[100] = "je suis src";
	char	dest[100] = "bonjour les amis";

	if ( (((uintptr_t) ft_strncpy(dest, src, 10)) != ((uintptr_t) dest)) || strcmp(dest, "je suis srs amis") != 0 )
	{
		puts("STRNCPY FAIL 1");
		return ;
	}

	memset(src, 'A', 100);
	memset(dest, 'B', 100);

	if ( (((uintptr_t) ft_strncpy(dest, src, 20)) != ((uintptr_t) dest)) || memcmp(dest, "AAAAAAAAAAAAAAAAAAAABBB", 23) != 0 )
	{
		puts("STRNCPY FAIL 2");
		return ;
	}

	memset(src, 'Z', 5);
	src[5] = '\0';
	memset(dest, 'E', 100);

	if ( (((uintptr_t) ft_strncpy(dest, src, 10)) != ((uintptr_t) dest)) || memcmp(dest, "ZZZZZ\0\0\0\0\0EE", 12) != 0 )
	{
		puts("STRNCPY FAIL 3");
		return ;
	}

	puts("STRNCPY OK");
}

void	test_strcat(void)
{
	char	src[100] = "je suis src";
	char	dest[100] = "et moi dest";

	if ( (((uintptr_t) ft_strcat(dest, src)) != ((uintptr_t) dest)) || strcmp(dest, "et moi destje suis src") != 0 )
	{
		puts("STRCAT FAIL 1"); printf("\"%s\"\n", dest);
		return ;
	}

	if ( (((uintptr_t) ft_strcat(dest, "")) != ((uintptr_t) dest)) || strcmp(dest, "et moi destje suis src") != 0 )
	{
		puts("STRCAT FAIL 2");
		return ;
	}

	puts("STRCAT OK");
}

void	test_strncat(void)
{
	char	dest[100];

	memset(dest, 'A', 100);
	dest[0] = '\0';

	if ( (((uintptr_t) ft_strncat(dest, "bonjour", 7)) != ((uintptr_t) dest)) || memcmp(dest, "bonjour\0AA", 10) != 0 )
	{
		puts("STRNCAT FAIL 1");
		return ;
	}

	if ( (((uintptr_t) ft_strncat(dest, "bonjour", 7)) != ((uintptr_t) dest)) || memcmp(dest, "bonjourbonjour\0AA", 17) != 0 )
	{
		puts("STRNCAT FAIL 2");
		return ;
	}

	if ( (((uintptr_t) ft_strncat(dest, "bonjour", 3)) != ((uintptr_t) dest)) || memcmp(dest,"bonjourbonjourbon\0AA",20) != 0)
	{
		puts("STRNCAT FAIL 3");
		return ;
	}

	puts("STRNCAT OK");
}

void	test_strlcat(void)
{
	char	un[15] = "salut";
	char	deux[15] = "les amis";

	if ( ft_strlcat(un, deux, sizeof(un)) != 13 || strcmp(un, "salutles amis") != 0 )
	{
		puts("STRLCAT FAIL 1");
		return ;
	}

	char	tab[15] = "bonjourmdrlol";
	char	karotte[15] = {0};
	karotte[5] = 'Q';

	if ( ft_strlcat(karotte, tab, 6) != 13 || strcmp(karotte, "bonjo") != 0 )
	{
		puts("STRLCAT FAIL 2");
		return ;
	}
/*
	char	a[15] = "salut les amis";
	char	b[15] = "Z";

	if ( ft_strlcat(b, a, 30) != 15 || strcmp(b, "Zsalut les amis") != 0 )
	{
		puts("STRLCAT FAIL 3");
		return ;
	}
*/
	char	popo[15] = "carotte";
	char	pipi[15] = "XXX";

	if ( ft_strlcat(pipi, popo, 2) != 9 || strcmp(pipi, "XXX") != 0 )
	{
		puts("STRLCAT FAIL 4");
		return ;
	}

	char	oo[15] = "carotte";
	char	ii[15] = "XXX";

	if ( ft_strlcat(ii, oo, 3) != 10 || strcmp(ii, "XXX") != 0 )
	{
		puts("STRLCAT FAIL 5");
		return ;
	}

	puts("STRLCAT OK");
}

void	test_strchr(void)
{
	char 	str[] = "This is a sample string";
	char 	*ret;

	ret = ft_strchr(str, 's');
	if (ret - str + 1 != 4)
	{
		puts("STRCHR FAIL 1");
		return ;
	}

	ret = ft_strchr(ret + 1, 's');
	if (ret - str + 1 != 7)
	{
		puts("STRCHR FAIL 2");
		return ;
	}

	ret = ft_strchr(ret + 1, 's');
	if (ret - str + 1 != 11)
	{
		puts("STRCHR FAIL 3");
		return ;
	}

	ret = ft_strchr(ret + 1, 's');
	if (ret - str + 1 != 18)
	{
		puts("STRCHR FAIL 4");
		return ;
	}

	ret = ft_strchr(ret + 1, 's');
	if (ret != NULL)
	{
		puts("STRCHR FAIL 5");
		return ;
	}

	if ( ((uintptr_t) ft_strchr(str, '\0')) != ((uintptr_t) (&str[23])) )
	{
		puts("STRCHR FAIL 6");
		return ;
	}
	
	puts("STRCHR OK");
}

void	test_strrchr(void)
{
	char 	str[] = "This is a sample string";
	char 	*ret;
	
	ret = ft_strrchr(str, 's');
	if ( ((uintptr_t) ret) != ((uintptr_t) (&str[17])) )
	{
		puts("STRRCHR FAIL 1");
		return ;
	}

	str[17] = '\0';
	ret = ft_strrchr(str, 's');
	if ( ((uintptr_t) ret) != ((uintptr_t) (&str[10])) )
	{
		puts("STRRCHR FAIL 2");
		return ;
	}

	str[10] = '\0';
	ret = ft_strrchr(str, 's');
	if ( ((uintptr_t) ret) != ((uintptr_t) (&str[6])) )
	{
		puts("STRRCHR FAIL 3");
		return ;
	}

	str[6] = '\0';
	ret = ft_strrchr(str, 's');
	if ( ((uintptr_t) ret) != ((uintptr_t) (&str[3])) )
	{
		puts("STRRCHR FAIL 4");
		return ;
	}

	str[3] = '\0';
	if ( ft_strrchr(str, 's') != NULL )
	{
		puts("STRRCHR FAIL 5");
		return ;
	}

	ret = ft_strrchr(str, '\0');
	if ( ((uintptr_t) ret) != ((uintptr_t) (&str[3])) )
	{
		puts("STRRCHR FAIL 6");
		return ;
	}
	
	puts("STRRCHR OK");
}

void	test_strstr(void)
{
	char	tab[] = "je suis une chaine mdr lol";
	char	*ret;

	ret = ft_strstr(tab, "");
	if ( ((uintptr_t) ret) != ((uintptr_t) tab) )
	{
		puts("STRSTR FAIL 1");
		return ;
	}

	ret = ft_strstr(tab, "sui");
	if ( ((uintptr_t) ret) != ((uintptr_t) (&tab[3])) )
	{
		puts("STRSTR FAIL 2");
		return ;
	}

	ret = ft_strstr(tab, "m");
	if ( ((uintptr_t) ret) != ((uintptr_t) (&tab[19])) )
	{
		puts("STRSTR FAIL 3");
		return ;
	}

	ret = ft_strstr(tab, "mdr");
	if ( ((uintptr_t) ret) != ((uintptr_t) (&tab[19])) )
	{
		puts("STRSTR FAIL 4");
		return ;
	}

	ret = ft_strstr(tab, "lol");
	if ( ((uintptr_t) ret) != ((uintptr_t) (&tab[23])) )
	{
		puts("STRSTR FAIL 5");
		return ;
	}

	if ( ft_strstr(tab, "NULL") != NULL )
	{
		puts("STRSTR FAIL 6");
		return ;
	}

	ret = ft_strstr(tab, "j");
	if ( ((uintptr_t) ret) != ((uintptr_t) tab) )
	{
		puts("STRSTR FAIL 7");
		return ;
	}

	if ( ft_strstr(tab, "lola") != NULL )
	{
		puts("STRSTR FAIL 8");
		return ;
	}

	puts("STRSTR OK");
}

void	test_strnstr(void)
{
	char	tab[33] = "salut je suis une chaine ptdr\0xd";
	char	*ret;

	ret = ft_strnstr(tab, "dr", 30);
	if ( ((uintptr_t) ret) != ((uintptr_t) (&tab[27])) )
	{
		puts("STRNSTR FAIL 1");
		return ;
	}

	ret = ft_strnstr(tab, "NULL", sizeof(tab));
	if (ret != NULL)
	{
		puts("STRNSTR FAIL 2");
		return ;
	}

	ret = ft_strnstr(tab, "dr", 28);
	if (ret != NULL)
	{
		puts("STRNSTR FAIL 3");
		return ;
	}

	ret = ft_strnstr(tab, "", sizeof(tab));
	if ( ((uintptr_t) ret) != ((uintptr_t) tab) )
	{
		puts("STRNSTR FAIL 4");
		return ;
	}

	ret = ft_strnstr(tab, "salut", 30);
	if ( ((uintptr_t) ret) != ((uintptr_t) (&tab[0])) )
	{
		puts("STRNSTR FAIL 5");
		return ;
	}


	ret = ft_strnstr(tab, "je", 0);
	if (ret != NULL)
	{
		puts("STRNSTR FAIL 6");
		return ;
	}

	ret = ft_strnstr(tab, "xd", 100);
	if (ret != NULL)
	{
		puts("STRNSTR FAIL 7");
		return ;
	}
	
	puts("STRNSTR OK");
}

void	test_strcmp(void)
{
	if ( ft_strcmp("lol", "lol") != 0 )
	{
		puts("STRCMP FAIL 1");
		return ;
	}

	if ( ft_strcmp("", "") != 0 )
	{
		puts("STRCMP FAIL 2");
		return ;
	}

	if ( ft_strcmp("lol", "lola") >= 0 )
	{
		puts("STRCMP FAIL 3");
		return ;
	}

	if ( ft_strcmp("lola", "lol") <= 0 )
	{
		puts("STRCMP FAIL 4");
		return ;
	}

	if ( ft_strcmp("lola", "lolo") >= 0 )
	{
		puts("STRCMP FAIL 5");
		return ;
	}

	if ( ft_strcmp("a", "\200") >= 0 )
	{
		puts("STRCMP FAIL 6");
		return ;
	}

	puts("STRCMP OK");
}

void	test_strncmp(void)
{
	if ( ft_strncmp("lol", "lol", 3) != 0 )
	{
		puts("STRNCMP FAIL 1");
		return ;
	}

	if ( ft_strncmp("", "", 4) != 0 )
	{
		puts("STRNCMP FAIL 2");
		return ;
	}

	if ( ft_strncmp("lol", "lola", 4) >= 0 )
	{
		puts("STRNCMP FAIL 3");
		return ;
	}

	if ( ft_strncmp("lol", "lola", 3) != 0 )
	{
		puts("STRNCMP FAIL 4");
		return ;
	}

	if ( ft_strncmp("lola", "lol", 17) <= 0 )
	{
		puts("STRNCMP FAIL 5");
		return ;
	}

	if ( ft_strncmp("lola", "lolo", 4) >= 0 )
	{
		puts("STRNCMP FAIL 6");
		return ;
	}

	if ( ft_strncmp("a", "\200", 1) >= 0 )
	{
		puts("STRNCMP FAIL 7");
		return ;
	}

	puts("STRNCMP OK");
}

void	test_atoi(void)
{
	int 	expected[15] = {148, 148, 148, 148, -148, 0, 0, 0, 23, 10010, 12, 0, 2, 0, -68};
	char	*tab[15] = 
	{
		"148",
		"\v148.215",
		"   148.215",
		"   +148 + 34",
		"  \f -148 feuilles vivantes",
		"   +Il y a 148 feuilles 1",
		"- 148",
		"++148",
		"023",
		"10010",
		"12 12",
		"\010010",
		"  \n 2 \v -3",
		" ",
		"-68"
	};

	for (size_t i = 0 ; i < 15 ; ++i)
	{
		if ( ft_atoi(tab[i]) != expected[i] )
		{
			printf("ATOI FAIL %zu\n", i + 1);
			return ;
		}
	}

	puts("ATOI OK");
}

void	test_isalpha(void)
{
	for (int c = -15 ; c < 256 ; ++c)
	{
		if (( isalpha(c) > 0 && ft_isalpha(c) <= 0 ) || ( isalpha(c) == 0 && ft_isalpha(c) != 0 ))
		{
			printf("ISALPHA FAIL %d\n", c);
			return ;
		}
	}

	puts("ISALPHA OK");
}

void	test_isdigit(void)
{
	for (int c = -15 ; c < 256 ; ++c)
	{
		if (( isdigit(c) > 0 && ft_isdigit(c) <= 0 ) || ( isdigit(c) == 0 && ft_isdigit(c) != 0 ))
		{
			printf("ISDIGIT FAIL %d\n", c);
			return ;
		}
	}

	puts("ISDIGIT OK");
}

void	test_isalnum(void)
{
	for (int c = -15 ; c < 256 ; ++c)
	{
		if (( isalnum(c) > 0 && ft_isalnum(c) <= 0 ) || ( isalnum(c) == 0 && ft_isalnum(c) != 0 ))
		{
			printf("ISALNUM FAIL %d\n", c);
			return ;
		}
	}

	puts("ISALNUM OK");
}

void	test_isascii(void)
{
	for (int c = -15 ; c < 256 ; ++c)
	{
		if (( isascii(c) > 0 && ft_isascii(c) <= 0 ) || ( isascii(c) == 0 && ft_isascii(c) != 0 ))
		{
			printf("ISASCII FAIL %d\n", c);
			return ;
		}
	}

	puts("ISASCII OK");
}

void	test_isprint(void)
{
	for (int c = -15 ; c < 256 ; ++c)
	{
		if (( isprint(c) > 0 && ft_isprint(c) <= 0 ) || ( isprint(c) == 0 && ft_isprint(c) != 0 ))
		{
			printf("ISPRINT FAIL %d\n", c);
		}
	}

	puts("ISPRINT OK");
}

void	test_toupper(void)
{
	for (int c = -1 ; c < 256 ; ++c)
	{
		if ( toupper(c) != ft_toupper(c) )
		{
			printf("TOUPPER FAIL %d\n", c);
			return ;
		}
	}

	puts("TOUPPER OK");
}

void	test_tolower(void)
{
	for (int c = -1 ; c < 256 ; ++c)
	{
		if ( tolower(c) != ft_tolower(c) )
		{
			printf("TOLOWER FAIL %d\n", c);
			return ;
		}
	}

	puts("TOLOWER OK");
}

void	test_lstnew(void)
{
	t_list 	*ptr;
	int 	integer;
	char	*str;
	double	floating;
	struct 	s_lol
	{
		int 	integer;
		char	*str;
		double	floating;
	};
	struct s_lol	structure = {123, "une poule sur un mur", 123.456};

	integer = 42;
	ptr = ft_lstnew(&integer, sizeof(integer));
	if (ptr == NULL || ptr->content == NULL)
	{
		free(ptr);
		puts("LSTNEW FAIL 1");
		return ;
	}

	if (ptr->next != NULL || ptr->content_size != sizeof(integer) || *((int *)((*ptr).content)) != 42)
	{
		puts("LSTNEW FAIL 2");
		free(ptr->content); free(ptr);
		return ;
	}
	free(ptr->content); free(ptr);

	str = "je suis une chaine";
	ptr = ft_lstnew( str, strlen(str) + 1 );
	if (ptr == NULL || ptr->content == NULL)
	{
		free(ptr);
		puts("LSTNEW FAIL 3");
		return ;
	}

	if (  ptr->next != NULL || ptr->content_size != ( strlen(str) + 1 ) || strcmp(ptr->content, str) != 0  )
	{
		puts("LSTNEW FAIL 4");
		free(ptr->content); free(ptr);
		return ;
	}
	free(ptr->content); free(ptr);

	floating = 21.42;
	ptr = ft_lstnew(&floating, sizeof(floating));
	if (ptr == NULL || ptr->content == NULL)
	{
		free(ptr);
		puts("LSTNEW FAIL 5");
		return ;
	}

	if (ptr->next != NULL || ptr->content_size != sizeof(floating) || *((double *)((*ptr).content)) != floating)
	{
		puts("LSTNEW FAIL 6");
		free(ptr->content); free(ptr);
		return ;
	}
	free(ptr->content); free(ptr);

	ptr = ft_lstnew(&structure, sizeof(structure));
	if (ptr == NULL || ptr->content == NULL)
	{
		puts("LSTNEW FAIL 7");
		free(ptr);
		return ;
	}

	if (  ptr->next != NULL
	|| ptr->content_size != sizeof(structure)
	|| (*((struct s_lol *)((*ptr).content))).integer != structure.integer
	|| strcmp((*((struct s_lol *)((*ptr).content))).str, structure.str) != 0
	|| (*((struct s_lol *)((*ptr).content))).floating != structure.floating  )
	{
		puts("LSTNEW FAIL 8");
		free(ptr->content); free(ptr);
		return ;
	}
	free(ptr->content); free(ptr);

	ptr = ft_lstnew(NULL, 8976);
	if (ptr == NULL || ptr->content != NULL)
	{
		puts("LSTNEW FAIL 9");
		free(ptr->content); free(ptr);
	}

	if (ptr->next != NULL || ptr->content_size != 0)
	{
		puts("LSTNEW FAIL 10");
		free(ptr);
		return ;
	}
	free(ptr);

	puts("LSTNEW OK");
}

void	test_lstdelone(void)
{
	struct s_list	*ptr;

	ptr = ft_lstnew("string", 7);
	ft_lstdelone( &ptr, &lst_del_lol );

	if (ptr != NULL)
	{
		free(ptr);
		puts("LSTDELONE FAIL 1 (possibles fuites de mémoire suite à la fonction ft_lstdelone() mal faite");
		return ;
	}

	puts("LSTDELONE OK");
}

void	test_lstdel(void)
{
	t_list	*ptr;
	t_list	*tmp;
	t_list	*first;
	int 	i;

	i = 1;
	ptr = ft_lstnew(&i, sizeof(int));
	tmp = ptr;
	first = ptr;

	i = 2;
	ptr = ft_lstnew(&i, sizeof(int));
	tmp->next = ptr;
	tmp = ptr;

	i = 3;
	ptr = ft_lstnew(&i, sizeof(int));
	tmp->next = ptr;
	tmp = ptr;

	i = 4;
	ptr = ft_lstnew(&i, sizeof(int));
	tmp->next = ptr;
	tmp = ptr;

	/*while (first != NULL)
	{
		printf("%d -> ", *(int *)(first->content) );
		first = first->next;
	}
	puts("NULL");*/

	ft_lstdel(&first, &lst_del_lol);

	if (first != NULL)
	{
		puts("LSTDEL FAIL 1");
		return ;
	}

	puts("LSTDEL OK");
}

void	test_lstmap(void)
{
	t_list	*ptr;
	t_list	*tmp;
	t_list	*first;
	int 	i;

	//puts("LSTMAP CHECK TEST START");

	i = 1;
	ptr = ft_lstnew(&i, sizeof(int));
	tmp = ptr;
	first = ptr;

	i = 2;
	ptr = ft_lstnew(&i, sizeof(int));
	tmp->next = ptr;
	tmp = ptr;

	i = 3;
	ptr = ft_lstnew(&i, sizeof(int));
	tmp->next = ptr;
	tmp = ptr;

	i = 4;
	ptr = ft_lstnew(&i, sizeof(int));
	tmp->next = ptr;
	tmp = ptr;

	t_list	*lstmap = ft_lstmap(first, &funclstmap);


	// check si la premiere liste est bien toujours la meme
	if ( *(int *)(first->content) != 1 
	|| *(int *)(first->next->content) != 2
	|| *(int *)(first->next->next->content)  != 3
	|| *(int *)(first->next->next->next->content) != 4 )
	{
		puts("LSTMAP FAIL 1 (might be memory leaks)");
		return ;
	}

	// check si la nouvelle liste est bonne
	if ( *(int *)(lstmap->content) != 2 
	|| *(int *)(lstmap->next->content) != 3
	|| *(int *)(lstmap->next->next->content)  != 4
	|| *(int *)(lstmap->next->next->next->content) != 5 )
	{
		puts("LSTMAP FAIL 2 (might be memory leaks)");
		return ;
	}

	puts("LSTMAP OK");

/*
	puts("\tFirst list = 1 2 3 4");
	putchar('\t');
	while (first != NULL)
	{
		printf("%d -> ", *(int *)(first->content) );
		first = first->next;
	}
	puts("NULL");

	puts("\tnouvelle liste = 2 3 4 5");
	putchar('\t');
	while (lstmap != NULL)
	{
		printf("%d -> ", *(int *)(lstmap->content) );
		lstmap = lstmap->next;
	}
	puts("NULL");

	puts("LSTMAP CHECK TEST END");
*/
}


int		main(void)
{
	/*
		LES FONCTIONS NE SONT PAS TOUTES PARFAITEMENT BIEN VERIFIEES/CONTROLEES, CE MAIN DE TEST EST UNE AIDE
		MAIS N'EST PAS FIABLE A 100% ! IL FAUT REGARDER LE CODE DE CHAQUE FONCTION POUR VERIFIER QUE C'EST BON !
		(CERTAINES FONCTIONS NE SONT MEME PAS VRAIMENT VERIFIEES MEME SI C'EST ECRIT OK ...)
	*/

	atexit( &do_at_exit );

	test_memalloc();
	test_memdel();
	test_strnew();
	test_strdel();
	test_strclr();
	test_striter();
	test_striteri();
	test_strmap();
	test_strmapi();
	test_strequ();
	test_strnequ();
	test_strsub();
	test_strjoin();
	test_strtrim();
	test_strsplit();
	test_itoa();
	test_putchar();
	test_putstr();
	test_putendl();
	test_putnbr();
	test_putchar_fd();
	test_putstr_fd();
	test_putnbr_fd();

	test_memset();
	test_bzero();
	test_memcpy();
	test_memccpy();
	test_memmove();
	test_memchr();
	test_memcmp();
	test_strlen();
	test_strdup();
	test_strcpy();
	test_strncpy();
	test_strcat();
	test_strncat();
	test_strlcat();
	test_strchr();
	test_strrchr();
	test_strstr();
	test_strnstr();
	test_strcmp();
	test_strncmp();
	test_atoi();
	test_isalpha();
	test_isdigit();
	test_isalnum();
	test_isascii();
	test_isprint();
	test_toupper();
	test_tolower();

	test_lstnew();
	test_lstdelone();
	test_lstdel();
	test_lstmap();

	return (EXIT_SUCCESS);
}
