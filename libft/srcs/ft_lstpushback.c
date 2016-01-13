/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguillon <mguillon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 17:58:26 by mguillon          #+#    #+#             */
/*   Updated: 2015/08/07 11:34:23 by mguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpushback(t_list **begin_list, t_list *new)
{
	t_list *string;

	string = *begin_list;
	if (*begin_list)
	{
		while (string->next)
			string = string->next;
		string->next = new;
	}
	else
		*begin_list = new;
}
