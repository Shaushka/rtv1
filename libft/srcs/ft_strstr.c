/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguillon <mguillon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 20:03:54 by mguillon          #+#    #+#             */
/*   Updated: 2014/11/13 14:13:52 by mguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	size_t	k;

	i = 0;
	k = ft_strlen(s2);
	if (*s2 == '\0')
		return ((char*)s1);
	while (s1[i] != '\0')
	{
		if (ft_strncmp(&s1[i], s2, k) == 0)
			return ((char*)&s1[i]);
		i++;
	}
	return (NULL);
}
