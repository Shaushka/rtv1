/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkervran <gkervran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 13:17:25 by gkervran          #+#    #+#             */
/*   Updated: 2014/11/15 17:39:36 by gkervran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;
	void	*content_cp;
	size_t	content_size_cp;

	if ((new = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if ((content_cp = (void*)malloc(sizeof(char) * content_size)) == NULL)
		return (NULL);
	if (content)
		content_cp = ft_memcpy(content_cp, content, content_size);
	content_size_cp = content_size;
	if (!content)
	{
		new->content = NULL;
		new->content_size = 0;
		new->next = NULL;
	}
	else
	{
		new->content = content_cp;
		new->content_size = content_size_cp;
		new->next = NULL;
	}
	return (new);
}
