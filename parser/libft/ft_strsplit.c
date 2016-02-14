/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkervran <gkervran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 08:42:29 by gkervran          #+#    #+#             */
/*   Updated: 2015/04/03 17:54:11 by gkervran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_strlenc(char const *s, char c)
{
	int i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static int	ft_strcount(char const *s, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

static char	**alloc(char const *s, char c)
{
	int		i;
	int		j;
	char	**res;

	i = 0;
	j = 0;
	res = (char **)malloc((ft_strcount(s, c) + 1) * sizeof(char *));
	if (!(res))
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			res[j++] = (char*)malloc((ft_strlenc(s + i, c) + 1) * sizeof(char));
		if (!(res))
			return (NULL);
		while (s[i] != c && s[i])
			i++;
	}
	res[j] = NULL;
	return (res);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	if (!(s))
		return (NULL);
	res = alloc(s, c);
	while (res[j])
	{
		k = 0;
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i])
			res[j][k++] = s[i++];
		res[j++][k] = '\0';
	}
	return (res);
}
