/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 19:15:26 by mgras             #+#    #+#             */
/*   Updated: 2016/02/21 19:17:27 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_object		set_cylinder(t_vector pos, t_vector dir, float radius, float h)
{
	t_object	cylinder;

	cylinder.type = CYLINDER;
	cylinder.pos = pos;
	cylinder.dir = unit_vector(dir);
	cylinder.radius = radius;
	cylinder.height = h;
	cylinder.shine = 0;
	cylinder.reflect = 0;
	cylinder.checkered = 0;
	cylinder.refraction = 0;
	cylinder.cut = (t_vector){0, 0, 0};
	return (cylinder);
}

static float	m_calculus(t_vector cam, t_object cylinder, t_vector ray)
{
	float		m;

	m = dotpro_vector(unit_vector(ray), cylinder.dir) * norm_vector(ray)
		+ dotpro_vector(sub_vector(cam, cylinder.pos), cylinder.dir);
	if (cylinder.height > 0)
	{
		if (m < 0 || m > (cylinder.height))
			return (0);
	}
	if (item_cut(cam, ray, cylinder))
		return (0);
	return (m);
}

float			inter_cylinder(t_vector pos, t_vector ray, t_object cylinder)
{
	t_vector	tmp;
	float		a;
	float		b;
	float		c;
	float		det;

	tmp = sub_vector(pos, cylinder.pos);
	a = dotpro_vector(ray, ray)
		- (dotpro_vector(ray, cylinder.dir) * dotpro_vector(ray, cylinder.dir));
	b = 2 * (dotpro_vector(ray, tmp)
			- (dotpro_vector(ray, cylinder.dir)
				* dotpro_vector(tmp, cylinder.dir)));
	c = dotpro_vector(tmp, tmp)
		- (dotpro_vector(tmp, cylinder.dir) * dotpro_vector(tmp, cylinder.dir))
		- cylinder.radius * cylinder.radius;
	det = b * b - 4 * a * c;
	if (det < 0.0f)
		return (0);
	c = ((-b - sqrt(det)) / (2 * a));
	det = ((-b + sqrt(det)) / (2 * a));
	if ((det < 0 || c < det) && m_calculus(pos, cylinder, mult_vector(ray, c)))
		return (c);
	if ((c > 0 || det < c) && m_calculus(pos, cylinder, mult_vector(ray, det)))
		return (det);
	return (0);
}

t_vector		normal_cylinder(t_vector cam, t_object cylinder, t_vector ray)
{
	float		m;
	t_vector	tmp;

	m = m_calculus(cam, cylinder, ray);
	tmp = add_vector(sub_vector(cam, cylinder.pos), ray);
	tmp = unit_vector(sub_vector(tmp, mult_vector(cylinder.dir, m)));
	if (dotpro_vector(unit_vector(ray), tmp) > 0)
		return (mult_vector(tmp, -1));
	return (tmp);
}
