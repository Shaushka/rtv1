/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 19:07:52 by chuang            #+#    #+#             */
/*   Updated: 2016/01/18 19:26:41 by chuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "rtv1.h"
#include <math.h>

#define MAX_VISION 50

//sq = square
float		sq_segment(t_vector a)
{
	return (a.x * a.x + a.y * a.y + a.z * a.z);
}

// need a check
float		inter_sphere(t_vector cam, t_vector ray, t_sphere object)
{
	float			w;
	float			t;
	float			d;
	float			dist_sq_obj_ray;
	float			n_ray;
	t_vector		orig;

	w = 1;
	t = -1;
	n_ray = 0;
	orig = sub_vector(object.pos, cam);
	while ( w < MAX_VISION)
	{
		n_ray += norm_vector(ray);
		dist_sq_obj_ray = sq_segment((orig)) - (n_ray * n_ray);
		if (dist_sq_obj_ray <= (object.radius * object.radius))
		{
			d = sqrt((object.radius * object.radius) - (dist_sq_obj_ray * dist_sq_obj_ray));
			if (n_ray + d > 0 && n_ray + d < n_ray - d)
				t = n_ray + d;
			else if ( n_ray - d > 0 && n_ray - d < n_ray + d)
				t = n_ray - d;
			w = MAX_VISION;
		}
		else
			break;
		w++;
	}
	return (t);
}
