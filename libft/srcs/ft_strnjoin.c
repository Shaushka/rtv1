/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguillon <mguillon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 17:21:07 by mguillon          #+#    #+#             */
/*   Updated: 2015/08/07 11:36:49 by mguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(char const *s1, char const *s2, size_t len)
{
	char	*c;

	if (s1 && s2)
	{
		c = ft_strnew(ft_strlen(s1) + len);
		ft_strcpy(c, s1);
		c = ft_strncat((char *)c, s2, len);
		return (c);
	}
	return (NULL);
}
