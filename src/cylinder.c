/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 18:46:35 by chuang            #+#    #+#             */
/*   Updated: 2016/02/14 13:41:24 by chuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_object	set_cylinder(t_vector pos, t_vector dir, float radius, float height)
{
	t_object	cylinder;

	cylinder.type = CYLINDER;
	cylinder.pos = pos;
	cylinder.dir = unit_vector(dir);
	cylinder.radius = radius;
	cylinder.height = height;
	cylinder.shine = 0;
	return (cylinder);
}

float		inter_cylinder(t_vector cam_pos, t_vector ray, t_object cylinder)
{
	t_vector	tmp;
	float		a;
	float		b;
	float		c;
	float		det;

	tmp = sub_vector(cam_pos, cylinder.pos);
	a = dotpro_vector(ray, ray)
		- (dotpro_vector(ray, cylinder.dir) * dotpro_vector(ray, cylinder.dir));
	b = 2 * (dotpro_vector(ray, tmp)
			- (dotpro_vector(ray, cylinder.dir) * dotpro_vector(tmp, cylinder.dir)));
	c = dotpro_vector(tmp, tmp)
		- (dotpro_vector(tmp, cylinder.dir) * dotpro_vector(tmp, cylinder.dir))
		- cylinder.radius * cylinder.radius;
	det = b * b - 4 * a * c;
	if (det < 0.0f)
		return (0);
	if (((-b + sqrt(det)) / (2 * a)) < ((-b - sqrt(det)) / (2 * a)))
		return ((-b + sqrt(det)) / (2 * a));
	else
		return ((-b - sqrt(det)) / (2 * a));
}

t_vector	normal_cylinder(t_cam cam, t_object cylinder, t_vector ray)
{
	float		m;
	t_vector	tmp;

	tmp = set_vector(tmp, 0, 0, 0);
	m = dotpro_vector(unit_vector(ray), cylinder.dir) * norm_vector(ray)
		+ dotpro_vector(sub_vector(cam.pos, cylinder.pos), cylinder.dir);
//	if (cylinder.height > 0)
//	{
//		if (m < (cylinder.height / 2)  || m > (cylinder.height / 2))
//			return(tmp);
//	}
	tmp = add_vector(sub_vector(cam.pos, cylinder.pos), ray);
	return (unit_vector(sub_vector(tmp, mult_vector(cylinder.dir, m))));
}
