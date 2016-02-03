/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 19:07:52 by chuang            #+#    #+#             */
/*   Updated: 2016/02/03 13:44:13 by chuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "rtv1.h"
#include <math.h>

t_object	set_sphere(t_vector pos, float radius)
{
		t_object sphere;

		sphere.type = SPHERE;
		sphere.pos = pos;
		sphere.radius = radius;
		return (sphere);
}

float		inter_sphere(t_vector cam_pos, t_vector ray, t_object obj)
{
	float		a;
	float		b;
	float		c;
	float		det;
	float		t1;
	float		t2;
	t_vector	tmp;

	tmp = sub_vector(cam_pos, obj.pos);
	a = sq_vector(ray);
	b =  2 * dotpro_vector(tmp, ray);
	c = dotpro_vector(tmp, tmp) - (obj.radius * obj.radius);
	det = b * b - 4 * a * c;
	if (det < 0.0f)
		return (0);
	if (det != 0.0f)
	{
		t1 = (-b + sqrt(det)) / (2 * a);
		t2 = (-b - sqrt(det)) / (2 * a);
		if (t1 < t2)
			return (t1);
		else
			return (t2);
	}
	else
		return (-b / (2 * a));
}

t_vector		normal_sphere(t_cam cam, t_object obj, t_vector ray)
{
		t_vector	tmp;

	tmp = sub_vector(cam.pos, obj.pos);
	return(unit_vector(add_vector(ray, tmp)));
}
