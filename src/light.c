/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 18:02:33 by chuang            #+#    #+#             */
/*   Updated: 2016/01/22 17:26:14 by mguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <stdio.h>

#define MAX_VISION 50

t_color		diffuse_light(t_light light, t_color color, t_vector normal,t_vector inter)
{
	float		coef;
	t_vector	light_ray;

//plus distance courte plus lumiere faible
	light_ray = sub_vector(light.pos, inter);
	
	//PROTEGER LIGHT_RAY : IL DOIT ETRE > 0
	coef = dotpro_vector(unit_vector(light_ray), unit_vector(normal));
	coef = coef * light.intensity / norm_vector(light_ray);;
	color.r = ((color.r * light.intensity) + (light.color.r * coef)) / 2;
	color.g = ((color.g * light.intensity) + (light.color.g * coef)) / 2;
	color.b = ((color.b * light.intensity) + (light.color.b * coef)) / 2;
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

void	init_lights(t_env e)
{
	e.lights->pos = (t_vector){4.5,2,-1};
	e.lights->dir = (t_vector){0,1,0};
	e.lights->color = (t_color){255,255,255};
	e.lights->intensity = 1.5;
	e.lights->next = NULL;;
}
