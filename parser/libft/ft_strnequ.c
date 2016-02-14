/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkervran <gkervran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 17:47:06 by gkervran          #+#    #+#             */
/*   Updated: 2014/11/21 16:05:36 by gkervran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (s1 && s2)
	{
		if (s1[i] == '\0' && s2[i] == '\0')
			return (1);
		if (n == 0)
			return (1);
		while (s1[i] && s2[i] && i < n)
		{
			if (s1[i] == s2[i])
				i++;
			else
				return (0);
		}
		if ((s1[i] == '\0' && s2[i]) || (s1[i] && s2[i] == '\0'))
			return (0);
		return (1);
	}
	return (1);
}
