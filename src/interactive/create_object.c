/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 19:14:19 by mgras             #+#    #+#             */
/*   Updated: 2016/02/21 19:17:26 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "libft.h"

t_object		*create_object_p(void)
{
	t_object *a;

	a = (t_object*)malloc(sizeof(t_object));
	init_obj(a);
	if (a)
		return (a);
	else
		return (NULL);
}

t_light			*create_light_p(void)
{
	t_light		*a;

	a = (t_light*)malloc(sizeof(t_light));
	init_light(a);
	if (a)
		return (a);
	else
		return (NULL);
}

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

t_light			*create_light(t_env *e)
{
	t_light		*a;
	t_light		*b;

	a = (t_light*)malloc(sizeof(t_light));
	init_light(a);
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
