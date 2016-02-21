/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 19:16:38 by mgras             #+#    #+#             */
/*   Updated: 2016/02/21 19:17:27 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		check_shit(char *str)
{
	int				i;
	int				test;

	i = 0;
	test = 0;
	while (str[i])
	{
		if (str[i] == '/')
			test = 1;
		if (test == 1 && str[i] == '>')
			test = 2;
		i++;
	}
	if (test == 2)
		return (1);
	else
		return (0);
}

int		get_the_mark(char *str)
{
	int				i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '>')
			return (i);
		i++;
	}
	return (i);
}
