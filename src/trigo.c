/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radian.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 17:06:29 by chuang            #+#    #+#             */
/*   Updated: 2016/01/12 18:22:48 by chuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#define PI 3,14159265
#define RATIO (PI / 180)

float		d_cos(float angle)
{
	return (cos(angle * RATIO));
}

float		d_sin(float angle)
{
	return (sin(angle * RATIO));
}
float		d_acos(float value)
{
	return (d_acos(value) * (180 / PI));
}
