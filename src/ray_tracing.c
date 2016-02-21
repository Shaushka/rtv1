/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 19:20:27 by mgras             #+#    #+#             */
/*   Updated: 2016/02/21 19:20:28 by mgras            ###   ########.fr       */
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
	item = NULL;
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
	if (item)
	{
		return (ft_light(&(*e->lights), *item, mult_vector(ray, inter), e));
	}
	return ((t_color){0, 0, 0});
}
