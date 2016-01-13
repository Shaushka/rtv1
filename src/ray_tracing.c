/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 17:01:28 by chuang            #+#    #+#             */
/*   Updated: 2016/01/13 18:12:50 by agadiffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <math.h>

t_color		check_collision(t_env *e, t_vector ray)
{
	(void)e;
	(void)ray;
	return ((t_color){0,0,0});
}

void		ft_render(t_env *e)
{
	t_vector		ray;
	float			ratio;
	float			angle;
	int				x;
	int				y;
	int				addr;

	ratio = (float) SCREEN_W / (float) SCREEN_H;
	angle = tanf(PI *0.5f * FOV/180.);
	y = -1;
	while(++y < SCREEN_H)
	{
		x = -1;
		while (++x < SCREEN_W)
		{
			ray.x = (2 *((x) * INV_SCREEN_W) - 1) * angle * ratio;
			ray.y = (1 - 2 * ((y) * INV_SCREEN_H)) * angle;
			ray.z = -1;
			ray = unit_vector(ray);
			addr = y * e->mlx_init.img.sizeline + x * e->mlx_init.img.opp;
			//put_pixel_to_img(e, adrr, check_collide(e, ray));
			put_pixel_to_img(e, addr, (t_color){255,0,0});
		}
	}
}
