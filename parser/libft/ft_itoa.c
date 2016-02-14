/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkervran <gkervran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 10:15:55 by gkervran          #+#    #+#             */
/*   Updated: 2014/11/15 16:25:55 by gkervran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_flag(int *n)
{
	if (*n < 0)
	{
		*n = -*n;
		return (1);
	}
	return (0);
}

static int	ft_count(int s)
{
	int		count;

	count = 0;
	while (s > 9)
	{
		s = s / 10;
		count++;
	}
	return (count);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		count;
	int		flag;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	flag = ft_flag(&n);
	count = ft_count(n) + flag;
	if ((str = (char*)malloc(sizeof(char) * (count + 1))) == NULL)
		return (NULL);
	str[count + 1] = '\0';
	if (flag == 1)
		str[0] = '-';
	while (n > 9)
	{
		str[count] = ((n % 10) + 48);
		n = n / 10;
		count--;
	}
	str[0 + flag] = n + 48;
	return (&str[0]);
}
