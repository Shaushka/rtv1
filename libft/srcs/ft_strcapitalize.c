/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguillon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 20:12:50 by mguillon          #+#    #+#             */
/*   Updated: 2016/02/18 11:01:23 by mguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	if (str)
	{
		while (str[i] != '\0')
		{
			if (ft_isalpha_lower(str[i]))
				str[i] = str[i] - 'a' + 'A';
			else if (ft_isalpha_upper(str[i]))
				str[i] = str[i] - 'A' + 'a';
			i++;
		}
	}
	return (str);
}
