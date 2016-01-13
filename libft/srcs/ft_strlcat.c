/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguillon <mguillon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 14:21:07 by mguillon          #+#    #+#             */
/*   Updated: 2014/11/13 15:34:45 by mguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	int				j;
	int				nb;

	if (ft_memchr(dest, '\0', size) == NULL)
		return (size + ft_strlen(src));
	j = 0;
	i = ft_strlen(dest);
	nb = size - i;
	while (src[j] && j < nb - 1)
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (i + ft_strlen(src));
}
