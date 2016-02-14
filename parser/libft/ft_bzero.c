/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkervran <gkervran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 10:08:54 by gkervran          #+#    #+#             */
/*   Updated: 2014/11/21 16:23:02 by gkervran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*save;

	i = 0;
	if (s)
	{
		save = s;
		if (n == 0)
			return ;
		else
		{
			while (i < n)
			{
				save[i] = '\0';
				i++;
			}
		}
	}
}
