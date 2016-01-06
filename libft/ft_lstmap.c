/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguillon <mguillon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 17:56:19 by mguillon          #+#    #+#             */
/*   Updated: 2015/08/07 11:32:20 by mguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *tmp;

	new = NULL;
	tmp = NULL;
	while (lst)
	{
		tmp = ft_lstnew(lst->content, lst->content_size);
		if (tmp == NULL)
			return (NULL);
		ft_lstpushback(&new, f(tmp));
		lst = lst->next;
	}
	return (new);
}
