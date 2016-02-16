#include "../../libft/includes/libft.h"
#include "../../includes/rtv1.h"
#include <stdlib.h>
#include <stdio.h>

char		**remove_spaces(char *str, int i, char **clean)
{
	int j;

	j = 0;
	i = 0;
	char *tmp;
	printf("Je suis dans remove_spaces et tout va bien\n");
	tmp = *clean;
	while (str[i] != '\0')
	{
		if (ft_isspace(str[i]) || str[i] == '\n')
			i++;
		else
		{
			tmp[j] = str[i];
			i++;
			j++;
		}
	}
	printf("RS : Clean = \"%s\"\n", *clean);
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
		if (ft_isspace(str[i]) || str[i] == '\n')
		{
			j++;
			i++;
		}
		else
			i++;
	}
	len -= j;
	clean = malloc(sizeof(char) * (len + 1));
	printf("NMS : Clean = \"%s\"\n", clean);
	ft_bzero(clean, len + 1);
	return (*remove_spaces(str, i, &clean));
}

void		separators(char *str)
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
