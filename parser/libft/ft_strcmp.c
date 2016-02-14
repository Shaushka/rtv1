/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkervran <gkervran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 15:11:14 by gkervran          #+#    #+#             */
/*   Updated: 2014/11/25 18:25:45 by gkervran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int		i;
	int		result;

	i = 0;
	result = 0;
	if (!s1 || !s2)
		return (0);
	while ((unsigned char)s1[i] && (unsigned char)s2[i])
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			break ;
		i++;
	}
	result = (unsigned char)s1[i] - (unsigned char)s2[i];
	if (result < 0)
		result = -1;
	else if (result > 0)
		result = 1;
	return (result);
}
