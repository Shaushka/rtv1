/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 17:01:28 by chuang            #+#    #+#             */
/*   Updated: 2016/01/14 19:30:22 by chuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "libft.h"
#include <math.h>

t_color		check_collision(t_env *e, t_vector ray)
{
	float	inter;

	(void)e;
	inter = inter_sphere((t_vector){0,0,0}, ray, (t_sphere){(t_vector){5,0,0}, 0.5, NULL});
	if (inter > 0)
		return ((t_color) {255,255,0});
	return ((t_color){0,0,0});
}

/*
t_vector	ft_posHGV(t_cam cam)
{
	t_vector posHGV;

	posHGV = mult_vector(cam.u, distV);
	posHGV = add_vector(posHGV, mult_vector(cam.h, longV / 2));
	posHGV = sub_vector(posHGV, mult_vector(cam.d, largV / 2));
	return (posHGV);
}
*/

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
	y = 0;
	while(y < SCREEN_H)
	{
		x = -1;
		while (x < SCREEN_W)
		{
			ray.x = (2 *((x) * INV_SCREEN_W) - 1) * angle * ratio;
			ray.y = (1 - 2 * ((y) * INV_SCREEN_H)) * angle;
			ray.z = -1;
			ray = unit_vector(ray);
			addr = y * e->mlx_init.img.sizeline + x * e->mlx_init.img.opp;
			put_pixel_to_img(e, addr, check_collision(e, ray));
//			put_pixel_to_img(e, addr, (t_color){255, 255, 255});
			x++;
		}
		y++;
	}
}
