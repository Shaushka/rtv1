/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 17:31:14 by chuang            #+#    #+#             */
/*   Updated: 2016/01/12 16:47:03 by chuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

float		dotproduct(t_vect a, t_vect b)
{
	float		ret;

	ret = a.x * b.x + a.y * b.y + a.z * b.z;
	return (ret);
}

float		norm_vector(t_vect a)
{
	return(sqrt(a.x * a.x + a.y * a.y + a.z * a.z));
}

t_vector	unit_vector(t_vector v)
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
