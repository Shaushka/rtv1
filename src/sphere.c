/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 19:07:52 by chuang            #+#    #+#             */
/*   Updated: 2016/01/14 18:46:04 by chuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <math.h>

//sq = square
float		sq_segment(t_vector a)
{
	return (a.x * a.x + a.y * a.y + a.z * a.z);
}

// need a check
float		inter_sphere(t_vector cam, t_vector ray, item object)
{
	float			w;
	float			t;
	float			d;
	float			dist_sq_obj_ray;
	t_vector		s_ray;
	t_vector		orig;

	w = 1;
	s_ray = set_vector(0,0,0);
	orig = sub_vector(object->pos, cam);
	while ( w < MAX_VISION)
	{
		s_ray = add_vector(s_ray, ray);
		dist_sq_obj_ray = sq_segment((orig)) - sq_segment(vect_mult(ray, w));
		if (dist_sq_obj_ray < (object->radius * object->radius))
		{
			d = sqrt((object->radius * object->radius) - (dist_sq_obj_ray * dist_sq_obj_ray));
			if (s_ray + d > 0 && s_ray + d < s_ray - d)
				t = s_ray + d;
			else if ( s_ray - d > 0 && s_ray - d < s_ray + d)
				t = s_ray - d;
			w = MAX_VISION;
		}
		w++;
	}
	return (w);
}
