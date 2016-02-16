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

int			check_shadow(t_light light, t_vector inter_ray, t_env *e)
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
		if (test > 0.0001 && test < (float)norm_vector(light_ray))
		{
			return (1);
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
		normal = calc_normal(e->cam.pos, item, inter_ray);
	coef = dotpro_vector(unit_vector((light_ray)), unit_vector(normal));
	attenuation = ((100.f - norm_vector(light_ray)) / 100.f);
	if (attenuation < 0)
		attenuation = 0;
	coef *= (light.intensity - 0.1 * (norm_vector(inter_ray) / 10));
			if(coef > 1)
				coef = 1;
			if(coef < 0)
				coef = 0;
	return(coef);
}

t_vector	calc_normal(t_vector pos, t_object item, t_vector inter_ray)
{
	if (item.type == SPHERE)
		return(normal_sphere(pos, item, inter_ray));
	else if (item.type == PLANE)
		return(normal_plane(item, inter_ray));
	else if (item.type == CONE)
		return(normal_cone(pos, item, inter_ray));
	else
		return(normal_cylinder(pos, item, inter_ray));
}

float		specular_light(t_light light, t_object item, t_vector inter_ray, t_env *e)
{
	t_vector	shine;
	t_vector	light_ray;
	t_vector	normal;
	float		spec;

	light_ray = sub_vector(light.pos, add_vector(inter_ray, e->cam.pos));
	normal = calc_normal(e->cam.pos, item, inter_ray);
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
	t_color		tmp_color;
	float		coef;
	float		spec;
	float		shade;

	if (item.checkered == 1)
		item.color = mult_color(checkered_floor(inter_ray), AMBIANT);
	else
		item.color = mult_color(item.color, AMBIANT);
	while(lights)
	{
		coef = 0;
		spec = 0;
		if (!(shade = check_shadow(*lights, inter_ray, e)))
		{
			coef = diffuse_light(*lights, item, inter_ray, e);
			if (item.shine > 0 && coef)
				spec = specular_light(*lights, item, inter_ray, e);
			if (item.reflect > 0 && coef)
			{
				tmp_color = reflection(*lights, item, inter_ray, e);
				item.color = add_color(item.color, tmp_color);
			}
			tmp_color = mult_color(lights->color, (coef + spec));
			item.color = add_color(item.color, tmp_color);
		}
		lights = lights->next;
	}
	item.color = check_color(item.color);
	return (item.color);
}

void			init_lights(t_env *e)
{
//	t_light		*test;

/*	test = malloc(sizeof(t_light));
	test->pos = (t_vector){13, 0, 0};
	test->dir = (t_vector){0, 1, 0};
	test->color = (t_color){150, 150, 150};
	test->intensity = 0.1;
	test->next = NULL;*/
	e->lights = malloc(sizeof(t_light));
	e->lights->pos = (t_vector){0, 0, 0};
	e->lights->dir = (t_vector){0, 1, 0};
	e->lights->color = (t_color){150, 150, 150};
	e->lights->intensity = 0.4;
	e->lights->next = NULL;
}
