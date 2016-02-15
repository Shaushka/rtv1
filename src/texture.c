/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguillon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 10:39:23 by mguillon          #+#    #+#             */
/*   Updated: 2016/02/15 22:17:08 by mguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

#define TILE_LEN 0.5

t_color			checkered_floor(t_vector coord, t_vector normal)
{
	int	mpx;
	int	mpy;
	//int	mpz;
	t_color	color1;
	t_color	color2;
//	int a;
	
	color1 = (t_color){12, 232, 219};
	color2 = (t_color){12, 128, 232};

	mpx = (int)(fabs(coord.x) / (float)TILE_LEN) % 2;
	mpx = (coord.x < 0) ? (mpx + 1) % 2 : mpx;
	mpy = (int)(fabs(coord.y) / (float)TILE_LEN) % 2;
	mpy = (coord.y < 0) ? (mpy + 1) % 2 : mpy;
//	if (coord.x > 10 && coord.x < 11)
//		printf("Prof = %f, Height = %f, mpx = %d, mpy = %d\n", coord.x, coord.z, mpx, mpy);

 
//	mpz = (int)(coord.z / (float)TILE_LEN) % 2;
/*	if (coord.y >= 0)
		a = 1;
	else
		a = 0;
*/
 normal = (t_vector)normal; // ATTENTION : IL FAUT FAIRE LES VERTICALES EN UTILISANT LA NORMALE DU PLAN
//	if (mpz == 0)
//	{
		if (((mpx == 0 && mpy == 0) || (mpx != 0 && mpy != 0)))
			return (color1);
		else
			return (color2);
//	}
//	else
//	{
//		if (((mpx == 0 && mpy == 0) || (mpx != 0 && mpy != 0)))
//			return (color2);
//		else
//			return (color1);
//	}
}
