/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 17:31:14 by chuang            #+#    #+#             */
/*   Updated: 2016/01/26 19:06:50 by mguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <math.h>

t_vector		set_vector(t_vector v, float x, float y, float z)
{
	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

float			dotpro_vector(t_vector a, t_vector b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

float			norm_vector(t_vector a)
{
	return(sqrt(a.x * a.x + a.y * a.y + a.z * a.z));
}

t_vector		unit_vector(t_vector v)
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

t_vector		add_vector(t_vector a, t_vector b)
{
	t_vector		c;

	c.x = a.x + b.x;
	c.y = a.y + b.y;
	c.z = a.z + b.z;
	return (c);
}

t_vector		sub_vector(t_vector a, t_vector b)
{
	t_vector		c;

	c.x = a.x - b.x;
	c.y = a.y - b.y;
	c.z = a.z - b.z;
	return (c);
}

t_vector		cross_vector(t_vector a, t_vector b)
{
	t_vector		c;

	c.x = a.y * b.z - b.z * c.y;
	c.y = b.z * a.x - b.y * a.z;
	c.z = a.x * b.y - a.y * b.x;
	return(c);
}

t_vector		mult_vector(t_vector a, float m)
{
	a.x *= m;
	a.y *= m;
	a.z *= m;
	return (a);
}
