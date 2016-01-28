/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguillon <mguillon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 22:56:37 by mguillon          #+#    #+#             */
/*   Updated: 2016/01/28 17:00:32 by mguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_atoisspace(int c)
{
	return ((9 <= (char)c && (char)c <= 13) || (char)c == ' ');
}

int			ft_atoi(const char *str)
{
	char	is_neg;
	int		i;
	int		result;

	is_neg = 0;
	result = 0;
	i = 0;
	while (ft_atoisspace(str[i]))
		i++;
	if (str[i] == '-')
	{
		is_neg = 1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (is_neg)
		return (-result);
	else
		return (result);
}
