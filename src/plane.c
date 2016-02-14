/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguillon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 15:57:57 by mguillon          #+#    #+#             */
/*   Updated: 2016/02/14 13:41:09 by chuang           ###   ########.fr       */
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
	plane.radius = 0;
	plane.height = 0;
	plane.shine = 0;
	return (plane);
}

float		inter_plane(t_vector cam_pos, t_vector ray, t_object obj)
{
	float		t;

	t = -(dotpro_vector(obj.normal, sub_vector(cam_pos, obj.pos))
			/ (dotpro_vector(obj.normal, ray)));
	return (t);
}

t_vector	normal_plane(t_object obj, t_vector ray)
{
	if (dotpro_vector(obj.normal, unit_vector(ray)) > 0)
		obj.normal = mult_vector(obj.normal, -1);
	return (obj.normal);
}
