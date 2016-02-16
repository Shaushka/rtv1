
int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\f')
	{
		if (c == '\r' || c == '\f')
			return (1);
		else
			return (0);
	}
	else
		return (0);
}
