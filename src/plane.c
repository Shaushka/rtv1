/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguillon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 15:57:57 by mguillon          #+#    #+#             */
/*   Updated: 2016/01/30 15:52:47 by chuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <math.h>

t_object	set_plane(t_vector pos, t_vector normal)
{
	t_object	plane;

	plane.type = PLANE;
	plane.pos = pos;
	plane.normal = normal;
	plane.constant = 0;
	return (plane);
}

float		inter_plane(t_cam cam, t_vector ray, t_object obj)
{
	float		t;

	t = -((dotpro_vector(obj.normal, sub_vector(cam.pos, obj.pos)) + obj.constant)
			/ (dotpro_vector(obj.normal, ray)));
	return (t);
}

t_vector	normal_plane(t_object obj, t_vector ray)
{

	if (dotpro_vector(ray, obj.normal) < 0)
		obj.normal = mult_vector(obj.normal, -1);
	return (obj.normal);
}
