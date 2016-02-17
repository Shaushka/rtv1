/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguillon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 10:39:23 by mguillon          #+#    #+#             */
/*   Updated: 2016/02/17 14:19:48 by chuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"
#include <stdio.h>

#define TILE_LEN 0.5

int		check_odd (float pos)
{
	int mpx;
	mpx = (int)(fabs((pos + 0.0001) / (float)TILE_LEN)) % 2;
	return(pos > 0.f) ? (mpx + 1) % 2 : mpx;
}

t_color			checkered_floor(t_vector coord)
{
	int			mpx;
	int			mpy;
	int			mpz;
	t_color		color1;
	t_color		color2;

	color1 = (t_color){12, 232, 219};
	color2 = (t_color){12, 128, 232};
	mpx = 	
	mpy = (int)(fabs((coord.y + 0.0001) / (float)TILE_LEN)) % 2;
	mpy = (coord.y > 0.f) ? (mpy + 1) % 2 : mpy;
	mpz = (int)(fabs((coord.z + 0.0001) / (float)TILE_LEN)) % 2;
	mpz = (coord.z > 0.f) ? (mpz + 1) % 2 : mpz;
	if (mpy > 0)
	{
		if (((mpx == 0 && mpz == 0) || (mpx != 0 && mpz != 0)))
			return (color1);
		else
			return (color2);
	}
	else
	{
		if (((mpx == 0 && mpz == 0) || (mpx != 0 && mpz != 0)))
			return (color2);
		else
			return (color1);
	}
}
