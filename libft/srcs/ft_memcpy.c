/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguillon <mguillon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 11:18:37 by mguillon          #+#    #+#             */
/*   Updated: 2014/11/13 13:37:52 by mguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char			*ptrdst;
	const char		*ptrsrc;

	ptrdst = dst;
	ptrsrc = src;
	while (n--)
		*ptrdst++ = *ptrsrc++;
	return (dst);
}
