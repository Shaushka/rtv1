/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_vectors_clean.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 19:14:33 by mgras             #+#    #+#             */
/*   Updated: 2016/02/21 19:17:26 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "rtv1.h"

char		**remove_spaces(char *str, int i, char **clean)
{
	int		j;
	char	*tmp;

	j = 0;
	i = 0;
	tmp = *clean;
	while (str[i] != '\0' && str[i] != '\n')
	{
		if (ft_isspace(str[i]))
			i++;
		else
		{
			tmp[j] = str[i];
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
	len = ft_strlen(str);
	while (str[i] != '\0' && str[i] != '\n')
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
		if (str[i] == '/' || str[i] == '\n')
		{
			i++;
			while (str[i] == '/' || str[i] == '\n')
			{
				str[i] = ' ';
				j++;
			}
		}
		else
			i++;
	}
}
