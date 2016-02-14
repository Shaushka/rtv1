/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkervran <gkervran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:46:46 by gkervran          #+#    #+#             */
/*   Updated: 2014/11/15 14:07:08 by gkervran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_flag(const char *str)
{
	int		flag;

	flag = 2;
	if (str[0] == '+' || str[0] == '-')
	{
		if (str[0] == '+')
		{
			if (str[1] > 47 && str[1] < 58)
				flag = 1;
		}
		else if (str[0] == '-')
		{
			if (str[1] > 47 && str[1] < 58)
				flag = 0;
		}
		if (str[1] < 47 || str[1] > 58)
			return (-1);
	}
	return (flag);
}

static int	ft_calcul(const char *str)
{
	int		i;
	int		val;

	i = 0;
	val = 0;
	while (str[i] > 47 && str[i] < 58)
	{
		if (val != 0)
		{
			if ((val + (val * 10) + (str[i] - 48)) > 2147483647)
				return (-1);
			else
				val = (val * 10) + (str[i] - 48);
		}
		else
			val = str[i] - 48;
		i++;
	}
	return (val);
}

int			ft_atoi(const char *str)
{
	int		val;
	int		flag;
	int		i;

	if (!str || str[0] == '\0')
		return (0);
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	flag = ft_flag(&str[i]);
	if (flag != 2)
		i++;
	if (flag == (-1))
		return (0);
	val = ft_calcul(&str[i]);
	if (flag == 0)
	{
		if ((val = (val * (-1) - 1)) == 2147483647)
			return (-2147483648);
		val++;
	}
	return (val);
}
