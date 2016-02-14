/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkervran <gkervran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:47:21 by gkervran          #+#    #+#             */
/*   Updated: 2014/12/08 10:49:28 by gkervran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s1 && s2 && n)
	{
		if (s2[0] == '\0')
			return ((char *)s1);
		while (s1[j + i] != '\0' && s2[i] != '\0' && ((j + i) < n))
		{
			if (s1[i + j] == s2[i])
				i++;
			else
			{
				j++;
				i = 0;
			}
		}
		if (s2[i] == '\0')
			return ((char *)&s1[j]);
	}
	return (NULL);
}
