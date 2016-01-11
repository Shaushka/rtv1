/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 16:40:38 by chuang            #+#    #+#             */
/*   Updated: 2016/01/11 16:57:52 by chuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_vect		vect_angle(t_vect u, double o)
{
	t_vect		r;
	double		inv_o;
	double		cos_o;
	double		sin_o;

	inv_o = 1 - d_cos(o);
	cos_o = d_cos(o);
	sin_o = d_sin(o);
	r.x = d_cos(o) + u.x * u.x * inv_o
		+ u.x * u.y * inv_o - u.z * d_sin(o)
		+ u.x * u.z * inv_o + u.y * d_sin(o);
	r.y = u.y * u.x * inv_o + u.z * d_sin(o)
		+ d_cos(o) + u.y * u.y * inv_o
		+ u.y * u.z * inv_o - u.x * d_sin(o);
	r_z = u.x * u.z * inv_o - u.y * d_sin(o)
		+ u.z * u.y * inv_o + u.x * d_sin(o)
		+ cos(o) + u.z * u.z * inv_o;
	return (r);
}
