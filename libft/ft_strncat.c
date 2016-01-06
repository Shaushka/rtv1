/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguillon <mguillon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 15:25:46 by mguillon          #+#    #+#             */
/*   Updated: 2014/11/13 14:09:58 by mguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t j;

	i = 0;
	j = ft_strlen(s1);
	while (i < n && s2[i] != '\0')
	{
		s1[j] = s2[i];
		i++;
		j++;
	}
	s1[j] = '\0';
	return (s1);
}
