/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radian.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 17:06:29 by chuang            #+#    #+#             */
/*   Updated: 2016/02/12 17:39:32 by mguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <math.h>

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
