#include "../../libft/includes/libft.h"
#include <stdlib.h>
#include <stdio.h>

char		**remove_spaces(char *str, int i, char **str)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isspace(str[i]))
			i++;
		else
		{
			clean[j] = str[i];
			i++;
			j++;
		}
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
	len = ft_strlen(str);//longueur de la str sale
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
	len -= j;// len = longueur de la str propre
	clean = malloc(sizeof(char) * (len + 1));// malloc len propre + '\0'
	return (remove_spaces(str, i, &clean));
}

void		separators(char *str)//remplace les / en trop par des espaces
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '/')
		{
			i++;
			while (str[i] == '/')
			{
				str[i] = ' ';
				j++;
			}
		}
		else
			i++;
	}
}
