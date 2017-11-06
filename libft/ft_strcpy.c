char	*ft_strcpy(char *dest, const char *src)
{
	char	*ret;

	ret = dest;
	while ((*dest++ = *src++) != 0x00)
		;
	return (ret);
}