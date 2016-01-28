/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_verification.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguillon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 16:28:17 by mguillon          #+#    #+#             */
/*   Updated: 2016/01/28 17:22:11 by mguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include <stdlib.h>
#include <stdio.h>


char		*remove_spaces(char *str)
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
		{
			i++;
		}
	}
	len -= j;
	clean = malloc(sizeof(char) * (len + 1));
	i = 0;
	j = 0;
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

void	separators(char *str)//remplace les / en trop par des espaces
{
	int i;
	int j;

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

int		is_slashes_and_digits(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]) && str[i] != '/')
			return (0);
		else
			i++;
	}
	return (1);
}

int		is_vector(char *str)
{
	int i;
	int s;
	int n;

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
		if (str[i] == '/')
		{
			i++;
			s++;
		}
	}
	if (n == 3 && s == 2)
		return (1);
	else
		return (0);
}

int		correct_input(char *str)
{
	char *clean;
	char *final;
//	printf("\nWelcome to correct_input_land\n");
	clean = remove_spaces(str);
//	printf("After remove_spaces : %s\n", clean);
	if (is_slashes_and_digits(clean))
	{
//		printf("It's slashes and digits !\n");
		separators(clean);
//		printf("After separators : %s\n", clean);
		final = remove_spaces(clean);
//		printf("After remove_spaces again : %s\n", final);
		free(clean);
		if (is_vector(final))
			return (1);

	}
	return (0);
}
