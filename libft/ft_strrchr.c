/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguillon <mguillon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 19:11:50 by mguillon          #+#    #+#             */
/*   Updated: 2015/08/07 11:37:05 by mguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t i;

	i = ft_strlen(s);
	if ((char)c == '\0')
		return ((char*)&s[i]);
	while (i != 0)
	{
		if (s[i] == (char)c)
			return ((char*)&s[i]);
		i--;
	}
	if (s[i] == (char)c)
		return ((char*)&s[i]);
	else
		return (NULL);
}
