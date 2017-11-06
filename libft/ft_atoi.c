#include "libft.h"

int		ft_atoi(const char *str)
{
	int		ret;
	int		neg;

	while (!(ret = 0) && ft_strchr("\f\n\r\t\v ", *str) != NULL)
		++str;
	neg = (*str == '-') ? (-1) : (1);
	str = (*str == '-' || *str == '+') ? (str + 1) : (str);
	while (*str >= '0' && *str <= '9')
		ret = ret * 10 + *str++ - '0';
	return (ret * neg);
}