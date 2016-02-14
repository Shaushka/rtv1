/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkervran <gkervran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 16:47:03 by gkervran          #+#    #+#             */
/*   Updated: 2014/11/25 18:26:18 by gkervran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	if ((unsigned char)s1[0] == '\0')
		return ((unsigned char)'\0' - (unsigned char)s2[0]);
	else
	{
		while (i < n)
		{
			if ((unsigned char)s1[i] == '\0')
				return ((unsigned char)'\0' - (unsigned char)s2[i]);
			else if ((unsigned char)s2[i] == '\0')
				return ((unsigned char)s1[i] - (unsigned char)'\0');
			if ((unsigned char)s1[i] != (unsigned char)s2[i])
				return ((unsigned char)s1[i] - (unsigned char)s2[i]);
			else
				i++;
		}
	}
	return (0);
}
