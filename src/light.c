/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 18:02:33 by chuang            #+#    #+#             */
/*   Updated: 2016/01/22 15:53:39 by chuang           ###   ########.fr       */
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
