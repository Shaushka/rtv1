/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguillon <mguillon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 15:11:27 by mguillon          #+#    #+#             */
/*   Updated: 2014/11/13 13:37:26 by mguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ps;
	unsigned int	i;

	i = 0;
	if (s)
	{
		ps = (unsigned char *)s;
		while (i < n)
		{
			if (ps[i] == (unsigned char)c)
				return (&ps[i]);
			i++;
		}
	}
	return (NULL);
}
