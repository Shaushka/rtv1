/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 18:02:33 by chuang            #+#    #+#             */
/*   Updated: 2016/02/12 18:03:41 by chuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <stdio.h>
#include <stdlib.h>

t_color			check_color(t_color color)
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
	return (color);
}

float			check_shadow(t_light light, t_vector inter_ray, t_env *e)
{
	float		test;
	t_vector	inter_pos;
	t_vector	light_ray;
	t_object	*tmp;

	inter_pos = add_vector(inter_ray, e->cam.pos);
	light_ray = sub_vector(light.pos, inter_pos);
	// check shadow
	tmp = e->scene->l_obj;
	while (tmp)
	{
		test = 0;
		if (tmp->type == SPHERE)
			test = inter_sphere(inter_pos, unit_vector(light_ray), *tmp);
		else if (tmp->type == PLANE)
			test = inter_plane(inter_pos, unit_vector(light_ray), *tmp);
		else if (tmp->type == CONE)
			test = inter_cone(inter_pos, unit_vector(light_ray), *tmp);
		else if (tmp->type == CYLINDER)
			test = inter_cylinder(inter_pos, unit_vector(light_ray), *tmp);
		tmp = tmp->next;
		if (test > 0.1 && test < (float)norm_vector(light_ray))
		{
			return (test);
			//tmp = NULL;
		}
	}
	return (0);
}

float			diffuse_light(t_light light, t_object item, t_vector inter_ray, t_env *e)
{
	float		coef;
	float		attenuation;
	t_vector	light_ray;
	t_vector	normal;

	light_ray = sub_vector(light.pos, add_vector(inter_ray, e->cam.pos));
	if (check_shadow(light, inter_ray, e))
		light.intensity = 0;
	if (item.type == SPHERE)
		normal = normal_sphere(e->cam, item, inter_ray);
	else if (item.type == PLANE)
		normal = normal_plane(item, inter_ray); // call assigning normal function
	else if (item.type == CONE)
		normal = normal_cone(e->cam, item, inter_ray);
	else
		normal = normal_cylinder(e->cam, item, inter_ray);
	coef = dotpro_vector(unit_vector((light_ray)), unit_vector(normal));
	attenuation = ((100.f - norm_vector(light_ray)) / 100.f);
	if (attenuation < 0)
		attenuation = 0;
	coef *= light.intensity;
//	coef = coef * attenuation;
	return(coef);
/*	item.color.r = ((item.color.r + light.color.r * coef) * light.intensity) / 2;
	item.color.g = ((item.color.g + light.color.g * coef) * light.intensity) / 2;
	item.color.b = ((item.color.b + light.color.b * coef) * light.intensity) / 2;
	item.color = check_color(item.color);
	return (item.color);*/
}

float		specular_light(t_light light, t_object item, t_vector inter_ray, t_env *e)
{
	t_vector	reflect;
	t_vector	light_ray;
	t_vector	normal;
	float		spec;

	light_ray = sub_vector(light.pos, add_vector(inter_ray, e->cam.pos));
//	if (check_shadow(light, inter_ray, e))
//		normal = set_vector(normal, 0, 0, 0);
	if (item.type == SPHERE)
		normal = normal_sphere(e->cam, item, inter_ray);
	else if (item.type == PLANE)
		normal = normal_plane(item, inter_ray); // call assigning normal function
	else if (item.type == CONE)
		normal = normal_cone(e->cam, item, inter_ray);
	else 
		normal = normal_cylinder(e->cam, item, inter_ray);
	reflect = mult_vector(normal, (dotpro_vector(light_ray, normal) * 2.0f));
	reflect = sub_vector(reflect, light_ray);
	spec = dotpro_vector(sub_vector(inter_ray,e->cam.pos),reflect);
	if (spec > 0)
	spec = powf(spec, 20) * item.shine;
	else
		return (0);
	return(spec);
}

t_color		ft_light(t_light *lights, t_object item, t_vector inter_ray, t_env *e)
{
	float		coef;

	coef = 0;
	while(lights)
	{
		if (!check_shadow(*lights, inter_ray, e))
		{
		coef += diffuse_light(*lights, item, inter_ray, e);
//		if (item.shine)
//			coef += specular_light(*lights, item, inter_ray, e);
		}
		lights = lights->next;
	}
	item.color.r *= coef;
	item.color.g *= coef;
	item.color.b *= coef;
	item.color = check_color(item.color);
	return (item.color);
}

void			init_lights(t_env *e)
{
	e->lights = malloc(sizeof(t_light));
	e->lights->pos = (t_vector){3, 0, 0};
	e->lights->dir = (t_vector){0, 1, 0};
	e->lights->color = (t_color){255, 255, 255};
	e->lights->intensity = 1;
	e->lights->next = NULL;
}
