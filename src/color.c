/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 19:15:21 by mgras             #+#    #+#             */
/*   Updated: 2016/02/21 19:17:27 by mgras            ###   ########.fr       */
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

t_color		check_color(t_color color)
{
	if (color.r < 0)
		color.r = 0;
	if (color.g < 0)
		color.g = 0;
	if (color.b < 0)
		color.b = 0;
	if (color.r > 255)
		color.r = 255;
	if (color.g > 255)
		color.g = 255;
	if (color.b > 255)
		color.b = 255;
	return (color);
}
