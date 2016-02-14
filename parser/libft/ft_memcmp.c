/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkervran <gkervran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:18:02 by gkervran          #+#    #+#             */
/*   Updated: 2014/11/25 11:56:02 by gkervran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ss1;
	const unsigned char	*ss2;

	ss1 = s1;
	ss2 = s2;
	if (!s1 || !s2)
		return (0);
	while (n > 0)
	{
		if (*ss1 != *ss2)
		{
			return ((int)*ss1 - (int)*ss2);
		}
		n--;
		ss1++;
		ss2++;
	}
	return (0);
}
