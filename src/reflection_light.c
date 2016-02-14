/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection_light.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 16:54:59 by chuang            #+#    #+#             */
/*   Updated: 2016/02/14 21:44:42 by chuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#define MAX_DEPTH 3

	static int				depth = 0;

t_color		reflection(t_light light, t_object item, t_vector inter_ray, t_env *e)
{
	t_vector				light_ray;
	t_vector				reflect;
	t_vector				normal;
	t_color					c_tmp;
	t_color					color;

	color = (t_color){0,0,0};
	light_ray = sub_vector(light.pos, add_vector(inter_ray, e->cam.pos));
	if (item.type == SPHERE)
		normal = normal_sphere(e->cam, item, inter_ray);
	else if (item.type == PLANE)
		normal = normal_plane(item, inter_ray); // call assigning normal function
	else if (item.type == CONE)
		normal = normal_cone(e->cam, item, inter_ray);
	else
		normal = normal_cylinder(e->cam, item, inter_ray);
	reflect = mult_vector(normal, (2.0f * dotpro_vector(light_ray, normal)));
	reflect = sub_vector(light_ray, reflect);
	depth++;
	if (depth < MAX_DEPTH)
	{
		c_tmp = check_collision(e, reflect);
		color = add_color(mult_color(c_tmp, item.reflect), color);
	}
	else
		depth = 0;
	return (color);
}
