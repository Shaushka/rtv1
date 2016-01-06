/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguillon <mguillon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 16:25:58 by mguillon          #+#    #+#             */
/*   Updated: 2014/11/13 13:37:40 by mguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ss1;
	unsigned char	*ss2;

	ss2 = 0;
	ss1 = 0;
	i = 0;
	if (s1 && s2 && n)
	{
		ss2 = (unsigned char*)s2;
		ss1 = (unsigned char*)s1;
		while (i < n)
		{
			if (ss1[i] != ss2[i])
				return (ss1[i] - ss2[i]);
			i++;
		}
	}
	return (0);
}
