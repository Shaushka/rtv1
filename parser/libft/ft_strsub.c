/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkervran <gkervran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 11:01:59 by gkervran          #+#    #+#             */
/*   Updated: 2015/04/03 17:54:35 by gkervran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*cpy;
	size_t	i;

	i = 0;
	if ((cpy = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	if (s && start < ft_strlen((char *)s))
	{
		while (i < len)
		{
			cpy[i] = s[start];
			start++;
			i++;
		}
		cpy[i] = '\0';
	}
	return (cpy);
}
