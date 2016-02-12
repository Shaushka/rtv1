/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguillon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 14:44:01 by mguillon          #+#    #+#             */
/*   Updated: 2016/02/12 17:41:30 by mguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <math.h>

t_vector	set_vector(t_vector v, float x, float y, float z)
{
	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

float		dotpro_vector(t_vector a, t_vector b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

float		norm_vector(t_vector a)
{
	return (sqrt(a.x * a.x + a.y * a.y + a.z * a.z));
}

t_vector	unit_vector(t_vector v)
{
	float norm;

	if ((norm = norm_vector(v)) != 1)
	{
		v.x /= (float)norm;
		v.y /= (float)norm;
		v.z /= (float)norm;
	}
	return (v);
}

float		sq_vector(t_vector a)
{
	return (a.x * a.x + a.y * a.y + a.z * a.z);
}
