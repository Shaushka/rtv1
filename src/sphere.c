/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 19:07:52 by chuang            #+#    #+#             */
/*   Updated: 2016/01/13 17:33:18 by chuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

//sq = square
float		sq_segment(t_vector a)
{
	return (a.x * a.x + a.y * a.y + a.z * a.z);
}

// need a check
float		inter_sphere(t_vect cam, t_vect ray, item object)
{
	float		w;
	float		dist_sq_obj_ray;
	t_vect		s_ray;
	t_vect		orig;

	w = 1;
	s_ray = ray;
	orig = sub_vector(object->pos, cam);
	while ( w < MAX_VIS)
	{
		s_ray = add_vector(s_ray, ray);
		dist_sq_obj_ray = sq_segment((orig)) - sq_segment(vect_mult(ray, w));
		if (dist_obj_ray < (object->radius * object->radius))
		{
			d = sqrt(object->radius * object->radius - dist_obj_ray);
			if (s_ray + d > 0 && s_ray + d < s_ray - d)
				t = s_ray + d;
			else if ( s_ray - d > 0 && s_ray - d < s_ray + d)
				t = s_ray - d;
			w = MAX_VIS;
		}
		w++;
	}
	return (w);
}
