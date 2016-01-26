/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 18:02:33 by chuang            #+#    #+#             */
/*   Updated: 2016/01/26 18:49:56 by chuang           ###   ########.fr       */
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
	t_vector	light_ray;

	light_ray = sub_vector(light.pos, inter);
	coef = dotpro_vector(unit_vector(light_ray), unit_vector(normal));
	coef = coef * light.intensity * ((MAX_VISION(0) - norm_vector(light_ray)) / 5000);
	color.r = ((color.r * light.intensity) + (light.color.r * coef)) / 2;
	color.g = ((color.g * light.intensity) + (light.color.g * coef)) / 2;
	color.b = ((color.b * light.intensity) + (light.color.b * coef)) / 2;
	color = check_color(color);
	return(color);
}

void	init_lights(t_env e)
{
	e.lights->pos = (t_vector){8, 0,1};
	e.lights->dir = (t_vector){0,1,0};
	e.lights->color = (t_color){255,255,255};
	e.lights->intensity = 1.5;
	e.lights->next = NULL;;
}
