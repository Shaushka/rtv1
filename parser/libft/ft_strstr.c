/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkervran <gkervran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:27:03 by gkervran          #+#    #+#             */
/*   Updated: 2014/11/26 12:12:01 by gkervran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s2[0] == '\0')
		return ((char *)s1);
	while (s1[i + j] != '\0' && s2[j] != '\0')
	{
		if (s1[i + j] == s2[j])
			j++;
		else
		{
			i++;
			j = 0;
		}
	}
	if (s2[j] == '\0')
		return ((char *)&s1[i]);
	return (NULL);
}
