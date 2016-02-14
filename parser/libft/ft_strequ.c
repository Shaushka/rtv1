/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkervran <gkervran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 17:43:53 by gkervran          #+#    #+#             */
/*   Updated: 2014/11/12 16:45:59 by gkervran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int		i;

	i = 0;
	if (s1 && s2)
	{
		while (s1[i] && s2[i])
		{
			if (s1[i] == s2[i])
				i++;
			else
				return (0);
		}
		if ((s1[i] == '\0') && (s2[i] == '\0'))
			return (1);
		else
			return (0);
	}
	else
		return (0);
}
