/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguillon <mguillon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 17:54:00 by mguillon          #+#    #+#             */
/*   Updated: 2015/08/07 11:31:47 by mguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *alst;
	while (tmp)
	{
		del(tmp->content, tmp->content_size);
		tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
	}
	*alst = NULL;
}
