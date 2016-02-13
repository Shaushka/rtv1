/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambiant_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 17:00:40 by chuang            #+#    #+#             */
/*   Updated: 2016/02/09 17:15:09 by chuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_color			mult_color(t_color color, float k)
{
	color.r *= k;
	color.g *= k;
	color.b *= k;
	return (color)
}

t_color			ambiant_light(t_object item)
{
	item.color = mult_color(item.color, AMBIANT)

	return (item.color);
}
