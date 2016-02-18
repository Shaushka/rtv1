/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguillon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 14:15:16 by mguillon          #+#    #+#             */
/*   Updated: 2016/02/18 14:40:26 by mgrimald         ###   ########.fr       */
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

t_light		*create_light(t_env *e)
{
	t_light		*a;
	t_light		*b;

	a = (t_light*)malloc(sizeof(t_light));
//	init_obj(a);
	if (e->scene->light == NULL)
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
