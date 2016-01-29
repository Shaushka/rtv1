/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_verification.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguillon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 16:28:17 by mguillon          #+#    #+#             */
/*   Updated: 2016/01/28 19:24:18 by mguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include <stdlib.h>
#include <stdio.h>

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
	clean = remove_spaces(str);
	if (is_slashes_and_digits(clean))
	{
		separators(clean);
		final = remove_spaces(clean);
		free(clean);
		if (is_vector(final))//attention, a ce stade on n'a pas verifie 
			//si les chiffres sont dans la fourchette demandee
			return (1);
	}
	return (0);
}
