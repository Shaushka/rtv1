/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguillon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 14:15:16 by mguillon          #+#    #+#             */
/*   Updated: 2016/02/12 14:16:44 by mguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../includes/rtv1.h"
#include "../libft/includes/libft.h"

t_object		*create_object(t_env *e)
{
	t_object *a;
	t_object *b;

	a = (t_object*)malloc(sizeof(t_object));
	init_obj(a);
	if (e->scene->l_obj == NULL)
	{
		e->scene->l_obj = a;
		if (e->scene->l_obj == NULL)
			return (NULL);
	}
	else
	{
		b = e->scene->l_obj;
		while (b->next != NULL)
			b = b->next;
		b->next = a;
	}
	return (a);
}
