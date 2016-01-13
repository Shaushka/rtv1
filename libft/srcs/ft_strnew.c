/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguillon <mguillon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 11:11:08 by mguillon          #+#    #+#             */
/*   Updated: 2014/11/13 14:11:04 by mguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	void	*ptr;

	ptr = (void*)ft_memalloc(size + 1);
	if (ptr == NULL)
		return ((char *)NULL);
	return ((char*)ptr);
}
