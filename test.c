#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
void	ft_putstr(char const *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
	}
}
size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

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

char		**remove_spaces(char *str, char **clean)
{
	int j;
	int k;
	char *tmp;

	j = 0;
	k = 0;

	tmp = *clean;
	while (str[k] != '\0')
	{
		if (!ft_isspace(str[k]))
		{
			tmp[j] = str[k];
			j++;
		}
		k++;
	}
	return (clean);
}

char		*no_more_spaces(char *str)
{
	char	*clean;
	int		len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	len = ft_strlen(str);
	while (str[i] != '\0')
	{
		if (ft_isspace(str[i]))
		{
			j++;
			i++;
		}
		else
			i++;
	}
	len -= j;
	clean = malloc(sizeof(char) * (len + 1));
	clean[len] = '\0';
	return (*remove_spaces(str, &clean));
}

int	main(void)
{
	char *str = malloc(sizeof(char) *6);
	str = "poney\0";
	no_more_spaces(str);
}
