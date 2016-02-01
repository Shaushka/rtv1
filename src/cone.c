/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 18:46:35 by chuang            #+#    #+#             */
/*   Updated: 2016/02/01 21:18:00 by chuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_object	set_cone(t_vector pos, t_vector dir, float radius, float height)
{
	t_object	cone;

	cone.type = CONE;
	cone.pos = pos;
	cone.dir = unit_vector(dir);
	cone.radius = radius;
	cone.height = height;
	return(cone);
}

float		inter_cone(t_cam cam, t_vector ray, t_object cone)
{
	t_vector	tmp;
	float		a;
	float		b;
	float		c;
	float		det;
	
	tmp = sub_vector(cam.pos, cone.pos);
	a = dotpro_vector(ray,ray)
		- ((1 + cone.radius * cone.radius) * dotpro_vector(ray, cone.dir)
				* dotpro_vector(ray, cone.dir));
	b = 2 * (dotpro_vector(ray, tmp)
			- ((1 - cone.radius * cone.radius) * dotpro_vector(ray, cone.dir)
				* dotpro_vector(tmp, cone.dir)));
	c = dotpro_vector(tmp, tmp)
		- ((1 + cone.radius * cone.radius) * dotpro_vector(tmp, cone.dir)
					* dotpro_vector(tmp,cone.dir));
	det = b*b - 4*a*c;
	if (det < 0.0f)
		return (0);
	else if (((-b + sqrt(det)) / (2 * a)) < ((-b - sqrt(det)) / (2 * a)))
		return ((-b + sqrt(det)) / (2 * a));
	else
		return ((-b - sqrt(det)) / (2 * a));
}

t_vector	normal_cone(t_object cone, t_vector ray, float inter, t_cam cam)
{
	float		m;
	t_vector	tmp;

	tmp = set_vector(tmp, 0, 0, 0);
	m = dotpro_vector(ray, cone.dir) * inter
		+ dotpro_vector(sub_vector(cam.pos, cone.pos), cone.dir);
//	if(m < -4 || m > 4)
//		return(tmp);
//	{
//		if (m < (-cone.height / 2.f)  || m > (cone.height / 2.f))
//			return(tmp);
//	}
	tmp = add_vector(sub_vector(cam.pos, cone.pos), mult_vector(ray,inter));
	tmp = sub_vector(tmp, mult_vector(cone.dir, m));
	tmp = unit_vector(sub_vector(tmp, mult_vector(cone.dir, (cone.radius * cone.radius * m))));
	return (tmp);
}
