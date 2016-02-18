/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 17:01:28 by chuang            #+#    #+#             */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "libft.h"
#include <math.h>

t_color		check_collision(t_env *e, t_vector ray, t_vector pos)
{
	float		inter;
	float		test;
	t_object	*tmp;
	t_object	*item;

	tmp = e->scene->l_obj;
	inter = 150.f;
	while (tmp)
	{
		test = intersection(tmp, ray, pos);
		if (test > 0.0001f && test < inter)
		{
			inter = test;
			item = tmp;
		}
		tmp = tmp->next;
	}
	if (inter > 0.0001f && inter < 150.f)
	{
		return (ft_light(&(*e->lights), *item, mult_vector(ray, inter), e));
	}
	return ((t_color){0, 0, 0});
}
