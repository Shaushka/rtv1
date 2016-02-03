/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 18:02:33 by chuang            #+#    #+#             */
/*   Updated: 2016/02/03 16:28:02 by chuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <stdio.h>
#include <stdlib.h>

t_color		check_color(t_color color)
{
	if (color.r < 0)
		color.r = 0;
	if (color.g < 0)
		color.g = 0;
	if (color.b < 0)
		color.b = 0;
	if (color.r > 255)
		color.r = 255;
	if (color.g > 255)
		color.g = 255;
	if (color.b > 255)
		color.b = 255;
	return(color);
}

t_color		diffuse_light(t_light light, t_object item, t_vector inter_ray, t_env *e)
{
	float		coef;
	float		attenuation;
	float		test;
	t_vector	light_ray;
	t_vector	normal;
	t_object	*tmp;

	light_ray = sub_vector(light.pos, add_vector(inter_ray, e->cam.pos));
	// check shadow
	tmp = e->scene->l_obj;
	while (tmp)
	{
		test = 0;
		if (tmp->type == SPHERE)
			test = inter_sphere(light.pos, unit_vector(light_ray), *tmp);
		else if(tmp->type == PLANE)
			test = inter_plane(light.pos, unit_vector(light_ray), *tmp);
		else if (tmp->type == CONE)
			test = inter_cone(light.pos, unit_vector(light_ray), *tmp);
		else if(tmp->type == CYLINDER)
			test = inter_cylinder(light.pos, unit_vector(light_ray), *tmp);
		if (-test > 0.01 && -test < (float)norm_vector(light_ray))
		{
			item.color = (t_color){item.color.r/10,item.color.g/10,item.color.b/10};
			light.intensity /= 4;
		}
	tmp = tmp->next;
	}
		if (item.type == SPHERE)
			normal = normal_sphere(e->cam, item, inter_ray);
		else if ( item.type == PLANE)
			normal = normal_plane(item, inter_ray); // call assigning normal function
		else if (item.type == CONE)
			normal = normal_cone(e->cam, item, inter_ray);
		else
			normal = normal_cylinder( e->cam, item, inter_ray);
	coef = dotpro_vector(unit_vector(light_ray), unit_vector(normal));
	attenuation = ((10.f - norm_vector(light_ray)) / 10.f) * 1.5;
	if (attenuation > 5)
		attenuation = 5;
	if (attenuation < 0)
		attenuation = 0;
//	coef = coef * attenuation;
	item.color.r = ((item.color.r + light.color.r * coef) * light.intensity) / 2;
	item.color.g = ((item.color.g + light.color.g * coef) * light.intensity) / 2;
	item.color.b = ((item.color.b + light.color.b * coef) * light.intensity) / 2;
	item.color = check_color(item.color);
	return(item.color);
}

void	init_lights(t_env *e)
{
	e->lights = malloc(sizeof(t_light));
	e->lights->pos = (t_vector){6, 0, 1};
	e->lights->dir = (t_vector){0,1,0};
	e->lights->color = (t_color){255,255,255};
	e->lights->intensity = 1;
	e->lights->next = NULL;
}
