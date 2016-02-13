/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 19:36:51 by chuang            #+#    #+#             */
/*   Updated: 2016/02/13 19:45:38 by chuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_color		mult_color(t_color color, float coef)
{
	color.r *= coef;
	color.g *= coef;
	color.b *= coef;
	return (color);
}

t_color		add_color(t_color a, t_color b)
{
	a.r += b.r;
	a.g += b.g;
	a.b += b.b;
	return (a);
}
