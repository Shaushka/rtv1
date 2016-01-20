/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 18:02:33 by chuang            #+#    #+#             */
/*   Updated: 2016/01/20 18:42:17 by chuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_color		diffuse_light(t_light light, t_color color, t_vector normal)
{
	float	coef;

	coef = dotpro_vector(light.dir, normal) * 0.5;
	color.r += light.color.r * coef;
	color.g += light.color.g * coef;
	color.b += light.color.b * coef;
	return(color);
}
