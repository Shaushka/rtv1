/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 19:16:09 by mgras             #+#    #+#             */
/*   Updated: 2016/02/21 19:17:27 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

float		intersection(t_object *tmp, t_vector ray, t_vector pos)
{
	if (tmp->type == SPHERE)
		return (inter_sphere(pos, ray, *tmp));
	else if (tmp->type == PLANE)
		return (inter_plane(pos, ray, *tmp));
	else if (tmp->type == CONE)
		return (inter_cone(pos, ray, *tmp));
	else if (tmp->type == CYLINDER)
		return (inter_cylinder(pos, ray, *tmp));
	return (0.f);
}
