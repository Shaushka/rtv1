/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguillon <mguillon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 13:55:14 by mguillon          #+#    #+#             */
/*   Updated: 2014/11/13 13:36:09 by mguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_writeindest(char *dest, int i, int n)
{
	int goto_i;

	goto_i = 0;
	if (n < 0)
	{
		dest[0] = '-';
		goto_i = 1;
		n = -n;
	}
	while (i > goto_i)
	{
		dest[i - 1] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	return (dest);
}

char		*ft_itoa(int n)
{
	char			*dest;
	int				i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 2147483647)
		return (ft_strdup("2147483647"));
	i = ft_numlen(n);
	if (n >= 0)
		dest = ft_strnew(i);
	else
	{
		dest = ft_strnew(i + 1);
		i++;
	}
	if (dest == NULL)
		return (NULL);
	return (ft_writeindest(dest, i, n));
}
