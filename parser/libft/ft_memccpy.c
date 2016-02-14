/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkervran <gkervran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 12:22:51 by gkervran          #+#    #+#             */
/*   Updated: 2014/11/25 16:36:02 by gkervran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char			*sdst;
	const unsigned char		*ssrc;
	unsigned char			sc;

	sdst = dst;
	ssrc = src;
	sc = c;
	while (n > 0)
	{
		if (*ssrc == sc)
		{
			*sdst = *ssrc;
			return (&sdst[1]);
		}
		*sdst = *ssrc;
		n--;
		sdst++;
		ssrc++;
	}
	return (NULL);
}
