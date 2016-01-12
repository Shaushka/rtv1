/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 19:07:52 by chuang            #+#    #+#             */
/*   Updated: 2016/01/12 19:22:09 by chuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

// need a check
float		inter_sphere(t_vect cam, t_vect ray, item object)
{
	float		w;
	t_vect		s_ray;
	t_vect		orig;

	w = 1;
	s_ray = ray;
	orig = vect_minus(object->pos, cam);
	while ( w < MAX_VIS)
	{
		s_ray = vect_add(s_ray, ray);
		//norm = absolu, vect_sq = puissance carre vect
		if (norm_vector(vect_sq(orig)) - (norm_vect(vect_sq(vect_minus(vect_mult(ray, w), cam))))
				< (object->radius * object->radius))
		{
			d = sqrt(object->radius * object->radius - (norm(vect_sq(orig))));
			t = s_ray + d > 0 && s_ray - d > s_ray + d  ? s_ray + d: s_ray - d;
			w = MAX_VIS;
		}
		w++;
	}
	return (w);
}
