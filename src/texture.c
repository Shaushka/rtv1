/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguillon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 10:39:23 by mguillon          #+#    #+#             */
/*   Updated: 2016/02/16 15:03:46 by chuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"
#include <stdio.h>

#define TILE_LEN 0.5

t_color			checkered_floor(t_vector coord, t_vector normal)
{
	int	mpx;
	int	mpy;
	int	mpz;
	t_color	color1;
	t_color	color2;
	
	color1 = (t_color){12, 232, 219};
	color2 = (t_color){12, 128, 232};

	mpx = (int)(fabs((coord.x + 0.0001) / (float)TILE_LEN)) % 2;
	mpx = (coord.x > 0.f) ? (mpx + 1) % 2 : mpx;
	
	mpy = (int)(fabs((coord.y + 0.0001) / (float)TILE_LEN)) % 2;
	mpy = (coord.y > 0.f) ? (mpy + 1) % 2 : mpy;
	mpz = (int)(fabs((coord.z + 0.0001) / (float)TILE_LEN)) % 2;
	mpz = (int)(coord.z > 0.f) ? (mpz + 1) % 2 : mpz;
	printf("x %d,y %d,z %d\n",mpx, mpy, mpz);
	printf("x %f,y %f,z %f\n",coord.x, coord.y, coord.z);
 normal = (t_vector)normal; // ATTENTION : IL FAUT FAIRE LES VERTICALES EN UTILISANT LA NORMALE DU PLAN
	if (mpy > 0)//!dotpro_vector(normal, (t_vector){0, 1, 0}))
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
