/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_specular.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 16:45:01 by chuang            #+#    #+#             */
/*   Updated: 2016/02/17 18:37:50 by chuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <stdio.h>

/*
** plus la specular est grande moins la tache est grande
*/
#define SPECULAR 64

float	specular_light(t_light light, t_object item, t_vector inter, t_env *e)
{
	t_vector	shine;
	t_vector	light_ray;
	t_vector	normal;
	float		spec;

	light_ray = unit_vector(sub_vector(light.pos, add_vector(inter, e->cam.pos)));
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
