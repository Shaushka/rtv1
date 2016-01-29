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
