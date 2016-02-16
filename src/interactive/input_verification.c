#include "../libft/includes/libft.h"
#include "../includes/rtv1.h"
#include <stdlib.h>
#include <stdio.h>

int				is_slashes_and_digits(char *str)
{
//	printf("STR en entrant dans isslashes...%s\n", str);
	int			i;

	i = 0;
	while (str[i] != '\0')
	{
//		printf("i :%c\n", str[i]);
		if (!ft_isdigit(str[i]) && str[i] != '/')
			return (0);
		else
			i++;
	}
	return (1);
}

int				is_vector(char *str)
{
	int			i;
	int			s;
	int			n;

	i = 0;
	s = 0;
	n = 0;
	if (!ft_isdigit(str[0]))
		return (0);
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]))
		{
			n++;
			while (ft_isdigit(str[i]) && str[i] != '\0')
				i++;
		}
		if (str[i++] == '/')
			s++;
	}
	if (n == 3 && s == 2)
		return (1);
	else
		return (0);
}

int				correct_input(char *str)
{
	char		*clean;
	char		*final;
	clean = no_more_spaces(str);
	if (is_slashes_and_digits(clean))
	{
		separators(clean);
		final = no_more_spaces(clean);
		printf("Good final =  \"%s\"\n", final);
		free(clean);
		if (is_vector(final))
		{
			printf("And it's a vector ! =  \"%s\"\n", final);
			return (1);
		}
	}
	else
		printf("It's not slashes and digits\n");
	printf("Bad final =  \"%s\"\n", clean);
	return (0);
}
