/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguillon <mguillon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 14:18:35 by mguillon          #+#    #+#             */
/*   Updated: 2014/11/13 15:26:47 by mguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int i;

	i = 0;
	if (n == 0)
		return (0);
	else
	{
		while (i < n - 1)
		{
			if (s1[i] == s2[i] && s1[i] != '\0')
				i++;
			else
				return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
}
