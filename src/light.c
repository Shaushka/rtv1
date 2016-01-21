/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 18:02:33 by chuang            #+#    #+#             */
/*   Updated: 2016/01/21 18:54:53 by chuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <stdio.h>


t_color		diffuse_light(t_light light, t_color color, t_vector normal,t_vector s_ray)
{
	float	coef;
//		float	tmp;
//		float	tmplight;

//plsu distance courte plus lumiere faible
	coef = dotpro_vector(normal, sub_vector(light.pos, s_ray)) * light.intensity;
	printf ("coef %f, L %f\n", coef, norm_vector(sub_vector(light.pos, s_ray)));
/*		tmp = color.r / 255.0;
		tmplight = light.color.r / 255.0;
		tmp = tmp + (tmplight) * coef;
		color.r = tmp * 127.5;
		tmp = color.g / 255.0;
		tmplight = light.color.g / 255.0;
		tmp = tmp + (tmplight) * coef;
		color.g = tmp * 127.5;
		tmp = color.b / 255.0;
		tmplight = light.color.b / 255.0;
		tmp = tmp + (tmplight) * coef;
		color.b = tmp * 127.5; */
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
//	printf("r %d,g %d,b %d \n", color.r, color.g, color.b);
	return(color);
}
