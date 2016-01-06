/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguillon <mguillon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 14:22:16 by mguillon          #+#    #+#             */
/*   Updated: 2015/08/07 13:25:50 by mguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*dst;

	i = 0;
	dst = NULL;
	if (f && s)
	{
		dst = (char*)malloc(sizeof(char) * ft_strlen(s) + 1);
		while (s[i] != '\0')
		{
			dst[i] = f(s[i]);
			i++;
		}
		dst[i] = '\0';
	}
	return (dst);
}
