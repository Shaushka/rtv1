/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 19:07:52 by chuang            #+#    #+#             */
/*   Updated: 2016/01/28 17:06:28 by chuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "rtv1.h"
#include <math.h>

float		inter_sphere(t_cam cam, t_vector ray, t_object obj)
{
	float		a;
	float		b;
	float		c;
	float		det;
	float		t1;
	float		t2;
	t_vector	tmp;

	tmp = sub_vector(cam.pos, obj.pos);
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

t_vector		normal_sphere(t_object obj, t_vector ray, float inter)
{
	return(unit_vector(sub_vector(mult_vector(ray, inter), obj.pos)));
}
