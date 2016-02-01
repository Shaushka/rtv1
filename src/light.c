/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 18:02:33 by chuang            #+#    #+#             */
/*   Updated: 2016/02/01 19:01:42 by chuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <stdio.h>

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

t_color		diffuse_light(t_light light, t_color color, t_vector normal,t_vector inter)
{
	float		coef;
	float		attenuation;
	t_vector	light_ray;

	light_ray = sub_vector(light.pos, inter);
	coef = dotpro_vector(unit_vector(light_ray), unit_vector(normal));
	attenuation = ((MAX_VISION(0) / 300) - norm_vector(light_ray)) / (MAX_VISION(0) / 300) * 2.5;
	if (attenuation > 5)
		attenuation = 5;
	if (attenuation < 1)
		attenuation = 1;
//	coef = coef * attenuation;
	color.r = ((color.r + light.color.r * coef) * light.intensity) / 2;
	color.g = ((color.g + light.color.g * coef) * light.intensity) / 2;
	color.b = ((color.b + light.color.b * coef) * light.intensity) / 2;
	color = check_color(color);
	return(color);
}

void	init_lights(t_env e)
{
	e.lights->pos = (t_vector){-1, 0, 0};
	e.lights->dir = (t_vector){0,1,0};
	e.lights->color = (t_color){255,255,255};
	e.lights->intensity = 0.7;
	e.lights->next = NULL;
}
