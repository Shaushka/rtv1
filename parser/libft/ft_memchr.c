/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkervran <gkervran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:09:28 by gkervran          #+#    #+#             */
/*   Updated: 2014/11/25 16:39:18 by gkervran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*save;
	unsigned char		ch;

	ch = c;
	if (s)
	{
		save = s;
		while (n > 0)
		{
			if (*save == ch)
				return ((void*)save);
			n--;
			save++;
		}
	}
	return (NULL);
}
