/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkervran <gkervran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 12:06:55 by gkervran          #+#    #+#             */
/*   Updated: 2014/11/26 16:22:03 by gkervran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*new;

	if (lst && f)
	{
		new = ft_lstnew("", 0);
		tmp = lst;
		while (lst && lst->next)
		{
			lst = f(lst);
			new = lst;
			lst = lst->next;
			new = new->next;
		}
		new = tmp;
		return (new);
	}
	return (NULL);
}
