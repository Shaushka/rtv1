/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trigo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 19:17:17 by mgras             #+#    #+#             */
/*   Updated: 2016/02/21 19:17:27 by mgras            ###   ########.fr       */
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
