/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkervran <gkervran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 17:00:10 by gkervran          #+#    #+#             */
/*   Updated: 2014/11/13 11:49:54 by gkervran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strchr(char *s, int c)
{
	int		i;
	char	find;

	i = 0;
	find = (char)c;
	if (find == '\0' && s[0] == '\0')
		return (&s[0]);
	while (s[i])
	{
		if (s[i] == find)
			return (&s[i]);
		i++;
	}
	if (find == '\0' && s[i] == '\0')
		return (&s[i]);
	return (NULL);
}
