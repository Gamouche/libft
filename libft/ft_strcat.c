char	*ft_strcat(char *dest, const char *src)
{
	char	*ret;

	ret = dest;
	while (*dest++ != '\0')
		;
	--dest;
	while ((*dest++ = *src++) != '\0')
		;
	return (ret);
	
}