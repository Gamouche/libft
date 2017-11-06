int		ft_strequ(char const *s1, char const *s2)
{
	while (*s1 == *s2 && *s1 != '\0')
	{
		++s1;
		++s2;
	}
	return ( (*s1 == '\0' && *s2 == '\0') ? (1) : (0) );
}