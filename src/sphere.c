/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 19:07:52 by chuang            #+#    #+#             */
/*   Updated: 2016/02/16 19:00:47 by chuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <math.h>

t_object		set_sphere(t_vector pos, float radius)
{
	t_object	sphere;

	sphere.type = SPHERE;
	sphere.pos = pos;
	sphere.radius = radius;
	sphere.height = 0;
	sphere.shine = 0;
	sphere.reflect = 0;
	sphere.checkered = 0;
	return (sphere);
}

float			inter_sphere(t_vector cam_pos, t_vector ray, t_object obj)
{
	float		a;
	float		b;
	float		c;
	float		det;
	float		t;

	cam_pos = sub_vector(cam_pos, obj.pos);
	a = sq_vector(ray);
	b = 2 * dotpro_vector(cam_pos, ray);
	c = dotpro_vector(cam_pos, cam_pos) - (obj.radius * obj.radius);
	det = b * b - 4 * a * c;
	if (det < 0.0f)
		return (0);
	t = (-b + sqrt(det)) / (2 * a);
	c = (-b - sqrt(det)) / (2 * a);
	if (t < c)
		return (t);
	return (c);
}

t_vector		normal_sphere(t_vector cam, t_object obj, t_vector ray)
{
	t_vector	tmp;

	tmp = sub_vector(cam, obj.pos);
	return (unit_vector(add_vector(ray, tmp)));
}
