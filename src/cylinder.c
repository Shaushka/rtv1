/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 18:46:35 by chuang            #+#    #+#             */
/*   Updated: 2016/01/30 13:54:46 by chuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_object	set_cylinder(t_vector pos, t_vector dir, float radius)
{
	t_object	cylinder;

	cylinder.pos = pos;
	cylinder.dir = unit_vector(dir);
	cylinder.radius = radius;
	return(cylinder);
}

float		inter_cylinder(t_cam cam, t_vector ray, t_object cylinder)
{
	t_vector	tmp;
	float		a;
	float		b;
	float		c;
	float		det;
	
	tmp = sub_vector(cam.pos, cylinder.pos);
	a = dotpro_vector(ray,ray)
		- (dotpro_vector(ray, cylinder.dir) * dotpro_vector(ray, cylinder.dir));
	b = 2 * (dotpro_vector(ray, tmp)
			- (dotpro_vector(ray, cylinder.dir) * dotpro_vector(tmp, cylinder.dir)));
	c = dotpro_vector(tmp, tmp)
		- (dotpro_vector(tmp, cylinder.dir) * dotpro_vector(tmp,cylinder.dir))
		- cylinder.radius * cylinder.radius;
	det = b*b - 4*a*c;
	if (det < 0.0f)
		return (0);
	if (((-b + sqrt(det)) / (2 * a)) < ((-b - sqrt(det)) / (2 * a)))
		return ((-b + sqrt(det)) / (2 * a));
	else
		return ((-b - sqrt(det)) / (2 * a));
}

t_vector	normal_cylinder(t_object cylinder, t_vector ray, float inter, t_cam cam)
{
	float		m;
	t_vector	tmp;

	m = dotpro_vector(ray, cylinder.dir) * inter
		+ dotpro_vector(sub_vector(cam.pos, cylinder.pos), cylinder.dir);
	tmp = sub_vector(add_vector(cam.pos, mult_vector(ray,inter)), cylinder.dir);
	return (unit_vector(sub_vector( mult_vector(cylinder.dir, m), tmp)));
}
