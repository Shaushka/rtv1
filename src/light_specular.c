/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_specular.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 19:16:20 by mgras             #+#    #+#             */
/*   Updated: 2016/02/21 19:18:24 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

/*
** plus la specular est grande moins la tache est grande
*/
#define SPECULAR 20

float	specular_light(t_light light, t_object item, t_vector inter, t_env *e)
{
	t_vector	shine;
	t_vector	light_ray;
	t_vector	normal;
	float		spec;

	light_ray = sub_vector(light.pos, add_vector(inter, e->cam.pos));
	light_ray = unit_vector(light_ray);
	normal = calc_normal(e->cam.pos, item, inter);
	shine = mult_vector(normal, (2.0f * dotpro_vector(light_ray, normal)));
	shine = sub_vector(light_ray, shine);
	spec = dotpro_vector(unit_vector(inter), unit_vector(shine));
	if (spec > 0)
	{
		spec = powf(spec, SPECULAR) * item.shine;
	}
	if (spec < 0)
		spec = 0;
	return (spec);
}
