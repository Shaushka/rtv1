/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 18:02:33 by chuang            #+#    #+#             */
/*   Updated: 2016/02/14 14:37:22 by chuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <stdio.h>
#include <stdlib.h>

#define SPECULAR 100 // plus la specular est grande moins la tache est grande
#define BLUR 5


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
		{
			test = inter_cylinder(inter_pos, unit_vector(light_ray), *tmp);
		}
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
			if(coef > 1)
				coef = 1;
			if(coef < 0)
				coef = 0;
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
	t_vector	shine;
	t_vector	light_ray;
	t_vector	normal;
	float		spec;

	light_ray = sub_vector(light.pos, add_vector(inter_ray, e->cam.pos));
	if (item.type == SPHERE)
		normal = normal_sphere(e->cam, item, inter_ray);
	else if (item.type == PLANE)
		normal = normal_plane(item, inter_ray); // call assigning normal function
	else if (item.type == CONE)
		normal = normal_cone(e->cam, item, inter_ray);
	else
		normal = normal_cylinder(e->cam, item, inter_ray);
	shine = mult_vector(normal, (2.0f * dotpro_vector(light_ray, normal)));
	shine = sub_vector(light_ray, shine);
	spec = dotpro_vector(inter_ray, shine);
	
	if (spec > 0)
	{
		spec = dotpro_vector(normal, shine) / norm_vector(shine);
		spec = powf(spec, SPECULAR) * item.shine;
	}
	if (spec > 20000)
		spec = 20000;
	if (spec < 0)
		spec = 0;
	return(spec);
}


t_color		ft_light(t_light *lights, t_object item, t_vector inter_ray, t_env *e)
{
	t_color		c_light;
	float		coef;
	float		spec;
	float		shade;

	item.color = mult_color(item.color, AMBIANT);
	while(lights)
	{
		coef = 0;
		spec = 0;
		if (!(shade = check_shadow(*lights, inter_ray, e)))
		{
			coef = diffuse_light(*lights, item, inter_ray, e);
			if (item.shine > 0)
				spec = specular_light(*lights, item, inter_ray, e);
			c_light = mult_color(lights->color, (coef + spec));
			item.color = add_color(item.color, c_light);
		}
		lights = lights->next;
	}
	item.color = check_color(item.color);
	return (item.color);
}

void			init_lights(t_env *e)
{
	t_light		*test;

	test = malloc(sizeof(t_light));
	test->pos = (t_vector){0, -2, 0};
	test->dir = (t_vector){0, 1, 0};
	test->color = (t_color){150, 150, 150};
	test->intensity = 0.2;
	test->next = NULL;
	e->lights = malloc(sizeof(t_light));
	e->lights->pos = (t_vector){0, -1.90, 0};
	e->lights->dir = (t_vector){0, 1, 0};
	e->lights->color = (t_color){150, 150, 150};
	e->lights->intensity = 0.2;
	e->lights->next = test;

	test = malloc(sizeof(t_light));
	test->pos = (t_vector){0, -1.8, 0};
	test->dir = (t_vector){0, 1, 0};
	test->color = (t_color){150, 150, 150};
	test->intensity = 0.2;
	test->next = e->lights;
	e->lights = test;
	test = malloc(sizeof(t_light));
	test->pos = (t_vector){0, -1.7, 0};
	test->dir = (t_vector){0, 1, 0};
	test->color = (t_color){150, 150, 150};
	test->intensity = 0.2;
	test->next = e->lights;
	e->lights = test;
	test = malloc(sizeof(t_light));
	test->pos = (t_vector){0, -1.6, 0};
	test->dir = (t_vector){0, 1, 0};
	test->color = (t_color){150, 150, 150};
	test->intensity = 0.2;
	test->next = e->lights;
	e->lights = test;

}
