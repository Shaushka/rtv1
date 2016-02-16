/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 16:40:38 by chuang            #+#    #+#             */
/*   Updated: 2016/02/16 18:26:41 by chuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

/* might not need it
** rodrigues rotation AKA Real rotation
** v = cos(o)U + (1-cos(o))(U dotproduct N) n + sin(o) (N /\U)
*/

t_vector		vect_rot_angle(t_vector u, float o)
{
	t_vect		v;
	float		inv_o;
	float		cos_o;
	float		sin_o;

	inv_o = 1 - d_cos(o);
	cos_o = d_cos(o);
	sin_o = d_sin(o);
	v.x = d_cos(o) + u.x * u.x * inv_o
		+ u.x * u.y * inv_o - u.z * d_sin(o)
		+ u.x * u.z * inv_o + u.y * d_sin(o);
	v.y = u.y * u.x * inv_o + u.z * d_sin(o)
		+ d_cos(o) + u.y * u.y * inv_o
		+ u.y * u.z * inv_o - u.x * d_sin(o);
	v.z = u.x * u.z * inv_o - u.y * d_sin(o)
		+ u.z * u.y * inv_o + u.x * d_sin(o)
		+ cos(o) + u.z * u.z * inv_o;
	return (v);
}
