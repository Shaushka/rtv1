/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radian.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 17:06:29 by chuang            #+#    #+#             */
/*   Updated: 2016/01/06 17:10:20 by chuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#define PI 3,14159265
#define RATIO (PI / 180)

double		d_cos(double angle)
{
	return (cos(angle * RATIO));
}