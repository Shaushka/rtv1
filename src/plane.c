/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 19:16:46 by mgras             #+#    #+#             */
/*   Updated: 2016/02/21 19:17:27 by mgras            ###   ########.fr       */
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
	plane.reflect = 0;
	plane.checkered = 0;
	plane.refraction = 0;
	plane.cut = (t_vector){0, 0, 0};
	return (plane);
}

int			square_plane(t_vector cam_pos, t_vector ray, t_object obj)
{
	t_vector	dist;

	dist = add_vector(cam_pos, ray);
	if ((fabs(dist.x - obj.pos.x)) < obj.height)
		if (fabs(dist.y - obj.pos.y) < obj.height)
			if (fabs(dist.z - obj.pos.z) < obj.height)
				return (1);
	return (-1);
}

int			round_plane(t_vector pos, t_vector ray, t_object obj)
{
	if (norm_vector(sub_vector(add_vector(ray, pos), obj.pos)) < obj.radius)
		return (1);
	return (-1);
}

float		inter_plane(t_vector cam_pos, t_vector ray, t_object obj)
{
	float		t;
	int			square;
	int			round;

	round = obj.dir.x * 4 ? obj.dir.x * 4 : 1;
	square = obj.dir.y * 4 ? obj.dir.y * 4 : 1;
	t = -(dotpro_vector(obj.normal, sub_vector(cam_pos, obj.pos))
			/ (dotpro_vector(obj.normal, ray)));
	if (t && obj.height > 0)
		square = square_plane(cam_pos, mult_vector(ray, t), obj) * round;
	if (t && obj.radius > 0)
		round = round_plane(cam_pos, mult_vector(ray, t), obj) * round;
	if ((round * square > 0) && !item_cut(cam_pos, mult_vector(ray, t), obj))
		return (t);
	else
		return (0);
}

t_vector	normal_plane(t_object obj, t_vector ray)
{
	if (dotpro_vector(obj.normal, unit_vector(ray)) > 0)
		obj.normal = mult_vector(obj.normal, -1);
	if (obj.dir.z * 4 > 0)
	{
		obj.normal.x = obj.normal.x + cos(ray.x);
		obj.normal.y = obj.normal.y + cos(ray.y);
		obj.normal.z = obj.normal.z + sin(ray.z);
	}
	return (obj.normal);
}
