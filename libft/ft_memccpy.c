/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguillon <mguillon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 11:18:37 by mguillon          #+#    #+#             */
/*   Updated: 2014/11/13 13:37:15 by mguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char			*ptrdst;
	const char		*ptrsrc;
	size_t			i;

	ptrdst = dst;
	ptrsrc = src;
	i = 0;
	while (i < n && ptrsrc[i] != (char)c)
	{
		ptrdst[i] = ptrsrc[i];
		i++;
	}
	if (i < n)
	{
		ptrdst[i] = ptrsrc[i];
		return (&ptrdst[i + 1]);
	}
	else
		return (NULL);
}
