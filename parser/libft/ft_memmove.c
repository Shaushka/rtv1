/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkervran <gkervran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 12:32:24 by gkervran          #+#    #+#             */
/*   Updated: 2014/11/25 16:57:21 by gkervran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*sdst;
	const unsigned char	*ssrc;

	if (!dst || !src)
		return (dst);
	sdst = dst;
	ssrc = src;
	if (ssrc < sdst)
	{
		while (len > 0)
		{
			sdst[len - 1] = ssrc[len - 1];
			len--;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
