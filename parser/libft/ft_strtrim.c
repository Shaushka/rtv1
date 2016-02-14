/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkervran <gkervran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 11:47:39 by gkervran          #+#    #+#             */
/*   Updated: 2014/11/25 18:28:31 by gkervran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		ft_beg_end(int *beg, int *end, char const *s)
{
	int		size;
	int		i;

	*beg = 0;
	*end = 0;
	i = 0;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i])
	{
		*beg += 1;
		i++;
	}
	i = 0;
	while (s[i])
		i++;
	size = i;
	i--;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && i >= 0)
	{
		*end += 1;
		i--;
	}
	size = size - *end - *beg;
	return (size);
}

char			*ft_strtrim(char const *s)
{
	char	*new;
	int		beg;
	int		end;
	int		i;
	int		size;

	if (s)
	{
		i = 0;
		if ((size = ft_beg_end(&beg, &end, s)) < 0)
			return (ft_strdup(""));
		if ((new = (char*)malloc(sizeof(char) * (size + 1))) == NULL)
			return (NULL);
		while (i < size && s[beg])
		{
			new[i] = s[beg];
			i++;
			beg++;
		}
		new[i] = '\0';
		return (new);
	}
	else
		return (NULL);
}
