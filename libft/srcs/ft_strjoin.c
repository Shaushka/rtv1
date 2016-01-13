/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguillon <mguillon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 16:00:11 by mguillon          #+#    #+#             */
/*   Updated: 2016/01/13 11:32:12 by agadiffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*c;

	if (s1 && s2)
	{
		c = ft_strnew(ft_strlen(s1) + (ft_strlen(s2)));
		if (c == NULL)
			return (NULL);
		ft_strcpy(c, s1);
		c = ft_strcat((char *)c, s2);
		return (c);
	}
	return (NULL);
}
