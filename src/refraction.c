/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refraction.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 19:16:56 by mgras             #+#    #+#             */
/*   Updated: 2016/02/21 20:03:53 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

#define REFRACTION 1.0f

/*
** REFRACTION = outside coeficient for refract mean outside resistance to light
*/

float		ft_cost(float eta, float cosi)
{
	return (1.0f - eta * eta * (1.0f - cosi * cosi));
}

float		inside(t_object item, t_vector inter, t_vector *joker)
{
	float eta;

	(void)joker;
	(void)inter;
	eta = REFRACTION / item.refraction;
	if (item.type == PLANE || (item.normal.x < 0) > 0)
	{
		eta = item.refraction / REFRACTION;
	}
	return (eta);
}

t_vector	ft_refray(t_vector inter, t_vector norm, float eta, float cosi)
{
	t_vector	refray;

	refray = mult_vector(unit_vector(inter), eta);
	norm = mult_vector(norm, (eta * cosi - sqrtf(ft_cost(eta, cosi))));
	refray = add_vector(refray, norm);
	refray = unit_vector(refray);
	return (refray);
}

t_color		refraction(t_object item, t_vector inter, t_env *e)
{
	t_vector		joker;
	t_vector		tmp;
	t_color			color;
	float			eta;
	float			cosi;

	color = (t_color){0, 0, 0};
	if (g_depth < MAX_DEPTH)
	{
		joker = calc_normal(e->cam.pos, item, inter);
		eta = inside(item, inter, &joker);
		cosi = -dotpro_vector(joker, inter);
		if (ft_cost(eta, cosi) > 0)
		{
			joker = ft_refray(inter, joker, eta, cosi);
			g_depth++;
			tmp = e->cam.pos;
			e->cam.pos = add_vector(inter, e->cam.pos);
			e->cam.pos = add_vector(e->cam.pos, mult_vector(joker, 1e-4));
			color = add_color(check_collision(e, joker, e->cam.pos), color);
			e->cam.pos = tmp;
			g_depth--;
		}
	}
	return (color);
}
