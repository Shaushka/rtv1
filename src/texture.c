/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 19:17:14 by mgras             #+#    #+#             */
/*   Updated: 2016/02/21 19:17:27 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"
#include <stdio.h>

#define TILE_LEN 0.5

static int		check_odd(float pos)
{
	int x;

	x = (int)(fabs((pos + 0.0001) / (float)TILE_LEN)) % 2;
	return (pos > 0.f ? (x + 1) % 2 : x);
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
	mpx = check_odd(coord.x);
	mpy = check_odd(coord.y);
	mpz = check_odd(coord.z);
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
