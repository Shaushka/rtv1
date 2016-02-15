/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguillon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 10:39:23 by mguillon          #+#    #+#             */
/*   Updated: 2016/02/15 17:31:37 by mguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

#define TILE_LEN 0.5

t_color			checkered_floor(t_vector coord)
{
	int	mpx;
	int	mpy;
	int	mpz;
	t_color	color1;
	t_color	color2;
//	int a;
	
	color1 = (t_color){12, 232, 219};
	color2 = (t_color){12, 128, 232};

	mpx = (int)(coord.x / TILE_LEN) % 2;
	mpy = (int)(coord.y / TILE_LEN) % 2;
	mpz = (int)(coord.z / TILE_LEN) % 2;
/*	if (coord.y >= 0)
		a = 1;
	else
		a = 0;
*/

	if (mpz == 0)
	{
		if (((mpx == 0 && mpy == 0) || (mpx != 0 && mpy != 0)))
			return (color1);
		else
			return (color2);
	}
	else
	{
		if (((mpx == 0 && mpy == 0) || (mpx != 0 && mpy != 0)))
			return (color2);
		else
			return (color1);
	}
}
