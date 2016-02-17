/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 18:46:35 by chuang            #+#    #+#             */
/*   Updated: 2016/02/17 19:49:05 by chuang           ###   ########.fr       */
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
	cone.shine = 0;
	cone.reflect = 0;
	cone.checkered = 0;
	return (cone);
}

static float	m_calculus(t_vector cam, t_object cone, t_vector ray)
{
	float	m;

	m = dotpro_vector(unit_vector(ray), cone.dir) * norm_vector(ray)
		+ dotpro_vector(sub_vector(cam, cone.pos), cone.dir);
	if (cone.height > 0)
	{
		if (m < (0) || (m > cone.height))
			return (0);
	}
	return (m);
}

float		inter_cone(t_vector cam_pos, t_vector ray, t_object cone)
{
	t_vector	tmp;
	float		a;
	float		b;
	float		c;
	float		det;

	tmp = sub_vector(cam_pos, cone.pos);
	a = dotpro_vector(ray, ray)
		- ((1 + cone.radius * cone.radius) * dotpro_vector(ray, cone.dir)
				* dotpro_vector(ray, cone.dir));
	b = 2 * (dotpro_vector(ray, tmp)
			- ((1 + cone.radius * cone.radius) * dotpro_vector(ray, cone.dir)
				* dotpro_vector(tmp, cone.dir)));
	c = dotpro_vector(tmp, tmp)
		- ((1 + cone.radius * cone.radius) * dotpro_vector(tmp, cone.dir)
					* dotpro_vector(tmp, cone.dir));
	det = b * b - 4 * a * c;
	if (det < 0.0f)
		return (0);
	else if (((-b + sqrt(det)) / (2 * a)) < ((-b - sqrt(det)) / (2 * a)))
		det = ((-b + sqrt(det)) / (2 * a));
	else
		det = ((-b - sqrt(det)) / (2 * a));
	if (m_calculus(cam_pos, cone, mult_vector(ray, det)))
		return (det);
	else
		return (0);
}

t_vector	normal_cone(t_vector cam, t_object cone, t_vector ray)
{
	float		m;
	t_vector	tmp;

	m = m_calculus(cam, cone, ray);
	tmp = set_vector(tmp, 0, 0, 0);
	tmp = add_vector(sub_vector(cam, cone.pos), ray);
	tmp = sub_vector(tmp, mult_vector(cone.dir, m));
	m *= cone.radius * cone.radius;
	tmp = unit_vector(sub_vector(tmp, mult_vector(cone.dir, m)));
	return (tmp);
}
