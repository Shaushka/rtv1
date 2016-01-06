/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguillon <mguillon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 13:00:24 by mguillon          #+#    #+#             */
/*   Updated: 2014/11/13 13:39:38 by mguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*tmps;
	char	*tmpd;

	tmps = (char *)src;
	tmpd = (char *)dest;
	if (tmps < tmpd)
	{
		while (n)
		{
			tmpd[n - 1] = tmps[n - 1];
			n--;
		}
	}
	else
		ft_memcpy(tmpd, tmps, n);
	return (tmpd);
}
