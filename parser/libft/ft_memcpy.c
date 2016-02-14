/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkervran <gkervran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 10:12:34 by gkervran          #+#    #+#             */
/*   Updated: 2014/11/09 17:10:22 by gkervran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*sdst;
	const char	*ssrc;

	sdst = dst;
	ssrc = src;
	while (n > 0)
	{
		*sdst = *ssrc;
		sdst++;
		ssrc++;
		n--;
	}
	return (dst);
}
