/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguillon <mguillon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 13:15:31 by mguillon          #+#    #+#             */
/*   Updated: 2016/01/13 11:47:07 by agadiffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	is_c(char str, char c)
{
	if (str == c)
		return (1);
	return (0);
}

static char	**ft_newtab(int n)
{
	char **str;

	str = (char **)malloc(sizeof(char*) * n);
	if (str)
		return (str);
	return (NULL);
}

static int	ft_count_all(char *str, char c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (is_c(str[i], c))
			i++;
		if (str[i])
			j++;
		while (str[i] && !is_c(str[i], c))
			i++;
	}
	return (j);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**dest;
	int		i;
	int		j;
	int		k;
	int		n;

	if (!s)
		return (NULL);
	n = ft_count_all((char *)s, c);
	i = 0;
	j = 0;
	if ((dest = ft_newtab(n + 1)) == NULL)
		return (NULL);
	while (s[i])
	{
		while (is_c(s[i], c))
			i++;
		k = i;
		while (s[i] && !is_c(s[i], c))
			i++;
		if (j != n)
			dest[j++] = ft_strsub(s, k, (i - k));
	}
	dest[n] = NULL;
	return (dest);
}
