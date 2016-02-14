/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkervran <gkervran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 09:53:26 by gkervran          #+#    #+#             */
/*   Updated: 2014/11/05 15:00:12 by gkervran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strrchr(char *s, int c)
{
	int		i;
	char	find;

	i = 0;
	find = (char)c;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == find)
			return (&s[i]);
		i--;
	}
	return (NULL);
}
