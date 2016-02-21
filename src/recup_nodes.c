/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_nodes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 19:16:54 by mgras             #+#    #+#             */
/*   Updated: 2016/02/21 19:17:27 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void		f_light_in(t_object **tmp_object, t_parse *parse, t_node *nodes)
{
	*tmp_object = create_object_p();
	parse->obj = *tmp_object;
	set_object_type(nodes->value, *tmp_object);
}

static void		not_f_light_in(t_object **tmp_object, t_node *nodes)
{
	(*tmp_object)->next = create_object_p();
	*tmp_object = (*tmp_object)->next;
	set_object_type(nodes->value, *tmp_object);
}

static void		if_light(t_light **tmp_light, t_node *nodes, t_parse *parse)
{
	if (ft_strcmp(nodes->type, "lighttype") == 0)
	{
		if (!(*tmp_light))
		{
			(*tmp_light) = create_light_p();
			parse->light = (*tmp_light);
		}
		else
		{
			(*tmp_light)->next = create_light_p();
			(*tmp_light) = (*tmp_light)->next;
		}
		set_light_type(nodes->value, (*tmp_light));
	}
	else
		set_light_param(nodes->type, nodes->value, (*tmp_light));
}

void			recup_nodes(t_node *nodes, t_parse *parse, t_env *e)
{
	t_object	*tmp_object;
	t_light		*tmp_light;

	(void)e;
	tmp_object = NULL;
	tmp_light = NULL;
	if (nodes && (nodes = nodes->next) != NULL)
	{
		while (nodes)
		{
			if (nodes->family == OBJECT)
			{
				if (ft_strcmp(nodes->type, "type") == 0 && !tmp_object)
					f_light_in(&tmp_object, parse, nodes);
				else if (ft_strcmp(nodes->type, "type") == 0 && tmp_object)
					not_f_light_in(&tmp_object, nodes);
				else
					set_object_param(nodes->type, nodes->value, tmp_object);
			}
			else if (nodes->family == LIGHT)
				if_light(&tmp_light, nodes, parse);
			nodes = nodes->next;
		}
	}
}
