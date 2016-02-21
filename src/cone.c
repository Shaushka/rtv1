/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 19:15:24 by mgras             #+#    #+#             */
/*   Updated: 2016/02/21 19:17:27 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_object		set_cone(t_vector pos, t_vector dir, float radius, float height)
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
	cone.refraction = 0;
	cone.cut = (t_vector){0, 0, 0};
	return (cone);
}

static float	m_calculus(t_vector cam, t_object cone, t_vector ray)
{
	float	m;

	if (item_cut(cam, ray, cone))
		return (0);
	m = dotpro_vector(unit_vector(ray), cone.dir) * norm_vector(ray)
		+ dotpro_vector(sub_vector(cam, cone.pos), cone.dir);
	if (cone.height > 0)
	{
		if (m < (0) || (m > cone.height))
			return (0);
	}
	return (m);
}

float			check_det(float d1, float d2, float m1, float m2)
{
	if (m1 == 0 && m2 == 0)
		return (0);
	else if (m1 == 0 && m2 != 0 && d2 > 0.0f)
		return (d2);
	else if (m1 != 0 && m2 == 0 && d1 > 0.0f)
		return (d1);
	if (d2 < 0.0f && d1 >= 0.0f)
		return (d1);
	else if (d1 < 0.0f && d2 >= 0.0f)
		return (d2);
	else if (d1 < 0.0f && d2 < 0.0f)
		return (0);
	return (d2 < d1 ? d2 : d1);
}

float			inter_cone(t_vector cam_pos, t_vector ray, t_object cone)
{
	t_vector	tmp;
	float		a;
	float		b;
	float		c;
	float		det;

	tmp = sub_vector(cam_pos, cone.pos);
	a = dotpro_vector(ray, ray) - ((1 + cone.radius * cone.radius)
			* dotpro_vector(ray, cone.dir) * dotpro_vector(ray, cone.dir));
	b = 2 * (dotpro_vector(ray, tmp)
			- ((1 + cone.radius * cone.radius) * dotpro_vector(ray, cone.dir)
				* dotpro_vector(tmp, cone.dir)));
	c = dotpro_vector(tmp, tmp) - ((1 + cone.radius * cone.radius)
			* dotpro_vector(tmp, cone.dir)
			* dotpro_vector(tmp, cone.dir));
	det = b * b - 4 * a * c;
	if (det < 0.0f)
		return (0);
	c = ((-b + sqrt(det)) / (2 * a));
	det = ((-b - sqrt(det)) / (2 * a));
	a = m_calculus(cam_pos, cone, mult_vector(ray, c));
	b = m_calculus(cam_pos, cone, mult_vector(ray, det));
	return (check_det(det, c, a, b));
}

t_vector		normal_cone(t_vector cam, t_object cone, t_vector ray)
{
	float		m;
	t_vector	tmp;

	m = m_calculus(cam, cone, ray);
	tmp = set_vector(tmp, 0, 0, 0);
	tmp = add_vector(sub_vector(cam, cone.pos), ray);
	tmp = sub_vector(tmp, mult_vector(cone.dir, m));
	m *= cone.radius * cone.radius;
	tmp = unit_vector(sub_vector(tmp, mult_vector(cone.dir, m)));
	if (dotpro_vector(unit_vector(ray), tmp) > 0)
		return (mult_vector(tmp, -1));
	return (tmp);
}
