/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection_light.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 16:54:59 by chuang            #+#    #+#             */
/*   Updated: 2016/02/17 17:00:09 by chuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#define MAX_DEPTH 3

static int		g_depth = 0;

t_vector	ray_reflect(t_vector normal, t_vector inter)
{
	t_vector		reflect;

	reflect = mult_vector(normal, (-2.0f * dotpro_vector(inter, normal)));
	reflect = add_vector(inter, reflect);
	return (reflect);
}

t_color		reflection( t_object item, t_vector inter, t_env *e)
{
	t_vector				reflect;
	t_color					c_tmp;
	t_color					color;
	t_vector				tmp;

	color = (t_color){0, 0, 0};
	c_tmp = (t_color){0, 0, 0};
	reflect = ray_reflect(calc_normal(e->cam.pos, item, inter), inter);
	if (g_depth < MAX_DEPTH)
	{
		g_depth++;
		tmp = e->cam.pos;
		e->cam.pos = add_vector(inter, tmp);
		c_tmp = check_collision(e, unit_vector(reflect), e->cam.pos);
		item.reflect = item.reflect > 1 ? 1 : item.reflect;
		color = add_color(mult_color(c_tmp, item.reflect), color);
		e->cam.pos = tmp;
		g_depth--;
	}
	return (color);
}
