/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguillon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 15:57:57 by mguillon          #+#    #+#             */
/*   Updated: 2016/01/27 16:30:36 by chuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <math.h>

float	inter_plane(t_cam cam, t_vector ray, t_plane obj)
{
	float		t;

	t = -((dotpro_vector(obj.normal, sub_vector(cam.pos, obj.pos)) + obj.constant)
			/ (dotpro_vector(obj.normal, ray)));
	return (t);
}
