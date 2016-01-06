/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguillon <mguillon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 22:33:45 by mguillon          #+#    #+#             */
/*   Updated: 2014/11/13 14:13:20 by mguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t k;

	i = 0;
	k = ft_strlen(s2);
	if (*s2 == '\0')
		return ((char*)s1);
	while (s1[i] != '\0' && i < n)
	{
		if (n - i < k)
			return (NULL);
		if (ft_strncmp(&s1[i], s2, k) == 0)
			return ((char*)&s1[i]);
		i++;
	}
	return (NULL);
}
