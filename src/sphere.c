/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 19:07:52 by chuang            #+#    #+#             */
/*   Updated: 2016/01/19 19:33:41 by agadiffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "rtv1.h"
#include <math.h>

#define MAX_VISION 50

float		sq_segment(t_vector a)
{
	return (a.x * a.x + a.y * a.y + a.z * a.z);
}

float		inter_sphere(t_cam cam, t_vector ray, t_sphere obj)
{
	float		a;
	float		b;
	float		c;
	float		det;
	float		t1;
	float		t2;
	t_vector	tmp;

	tmp = sub_vector(cam.pos, obj.pos);
	a = sq_segment(ray);
	b =  2 * dotpro_vector(tmp, ray);
	c = dotpro_vector(tmp, tmp) - (obj.radius * obj.radius);
	det = b * b - 4 * a * c;
	if (det < 0.0f)
		return (0);
	if (det != 0.0f)
	{
		t1 = (-b + sqrt(det)) / (2 * a);
		t2 = (-b - sqrt(det)) / (2 * a);
		if (t1 < t2)
			return (t1);
		else
			return (t2);
	}
	else
		return (-b / (2 * a)); 
}

/*
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
	while (w < MAX_VISION)
	{
		n_ray += norm_vector(ray);
		dist_sq_obj_ray = sq_segment((orig)) - (n_ray * n_ray);
		if (dist_sq_obj_ray <= (object.radius * object.radius))
		{
			d = sqrtf((object.radius * object.radius)
						- (dist_sq_obj_ray * dist_sq_obj_ray));
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
*/
