/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_verification.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 19:14:36 by mgras             #+#    #+#             */
/*   Updated: 2016/02/21 19:17:26 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "rtv1.h"

int				is_slashes_and_digits(char *str)
{
	int			i;

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

void			remove_bn(char **str)
{
	int			i;

	i = ft_strlen(*str);
	while (i >= 0 && *str[i] == '\n')
	{
		*str[i] = '\0';
		i--;
	}
}

int				correct_input(char *str)
{
	char		*clean;
	char		*final;

	remove_bn(&str);
	clean = no_more_spaces(str);
	if (is_slashes_and_digits(clean))
	{
		separators(clean);
		final = no_more_spaces(clean);
		free(clean);
		is_vector(final);
		return (1);
	}
	return (0);
}
