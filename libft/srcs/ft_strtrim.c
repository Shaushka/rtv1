/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 16:35:07 by mguillon          #+#    #+#             */
/*   Updated: 2016/02/19 15:49:16 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_trimisspace(int c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	else
		return (0);
}

char		*ft_strtrim(char const *s)
{
	int				i;
	const char		*start;
	const char		*end;
	int				j;

	i = 0;
	start = 0;
	end = 0;
	if (s)
	{
		if (*s == '\0')
			return (ft_strnew(0));
		j = ft_strlen(s) - 1;
		while (ft_trimisspace(s[i]))
			i++;
		start = &s[i];
		while (ft_trimisspace(s[j]) && 0 < j)
			j--;
		end = &s[j];
		if (start > end)
			return (ft_strnew(0));
		return (ft_strsub(start, 0, j - i + 1));
	}
	else
		return (NULL);
}
