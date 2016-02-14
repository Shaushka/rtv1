/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkervran <gkervran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 11:20:01 by gkervran          #+#    #+#             */
/*   Updated: 2015/04/03 17:17:50 by gkervran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*cpy;
	size_t		i;
	size_t		j;

	if (s1 && s2)
	{
		i = ft_strlen((char *)s1);
		j = ft_strlen((char *)s2);
		if ((cpy = (char *)malloc(sizeof(char) * (i + j + 1))) == NULL)
			return (NULL);
		cpy = ft_strcpy(cpy, (char *)s1);
		j = 0;
		while (s2[j])
		{
			cpy[i] = s2[j];
			i++;
			j++;
		}
		cpy[i] = '\0';
		return (cpy);
	}
	return (NULL);
}
