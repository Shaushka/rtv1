/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 17:31:14 by chuang            #+#    #+#             */
/*   Updated: 2016/01/12 20:01:54 by chuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

float			dotpro_vect(t_vector a, t_vector b)
{
	float		ret;

	ret = a.x * b.x + a.y * b.y + a.z * b.z;
	return (ret);
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
		v.x /= norm;
		v.y /= norm;
		v.z /= norm;
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
