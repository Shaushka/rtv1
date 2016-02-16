/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection_light.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 16:54:59 by chuang            #+#    #+#             */
/*   Updated: 2016/02/16 17:33:00 by chuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#define MAX_DEPTH 3

static int		g_depth = 0;

t_vector	ray_reflect(t_vector normal, t_vector light_ray)
{
	t_vector		reflect;

	reflect = mult_vector(normal, (2.0f * dotpro_vector(light_ray, normal)));
	reflect = sub_vector(light_ray, reflect);
	return (reflect);
}

t_color		reflection(t_light light, t_object item, t_vector inter, t_env *e)
{
	t_vector				reflect;
	t_color					c_tmp;
	t_color					color;
	t_vector				tmp;

	color = (t_color){0, 0, 0};
	c_tmp = (t_color){0, 0, 0};
	reflect = sub_vector(add_vector(inter, e->cam.pos), light.pos);
	reflect = ray_reflect(calc_normal(e->cam.pos, item, inter), reflect);
	if (g_depth < MAX_DEPTH)
	{
		tmp = e->cam.pos;
		e->cam.pos = inter;
		c_tmp = check_collision(e, unit_vector(reflect), inter);
		color = add_color(mult_color(c_tmp, item.reflect), color);
		e->cam.pos = tmp;
		g_depth++;
	}
	g_depth = 0;
	return (color);
}
