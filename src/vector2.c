/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 19:17:19 by mgras             #+#    #+#             */
/*   Updated: 2016/02/21 19:17:27 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <math.h>

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
	return (c);
}

t_vector		mult_vector(t_vector a, float m)
{
	a.x *= m;
	a.y *= m;
	a.z *= m;
	return (a);
}
