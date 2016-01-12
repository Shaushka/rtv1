/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 17:01:28 by chuang            #+#    #+#             */
/*   Updated: 2016/01/12 18:22:25 by chuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_color		check_collide(e, ray)
{
	

}

void		ft_render(env *e)
{
	t_vector		ray;
	float			degree;
	float			invW;
	float			invH;
	float			ratio;
	float			angle;
	int				x;
	int				y;

	invW = 1 / (float) WIN_WIDTH;
	invH = 1 / (float) WIN_HEIGHT;
	ratio = WIN_WIDTH / (float) WIDOW_HEIGHT;
	angle = tanf(PI *0.5f * FOV/180.);
		y = -1;
	while(++y < WINDOW_H)
	{
		x = -1;
		while (++x < WINDOW_W)
		{
			ray.x = (2 *((x) * invW) - 1) * angle * ratio;
			ray.y = (1 - 2 * ((y) * invH)) * angle;
			ray.z = -1;
			ray = unit_vector(ray);
			put_pxl_image(x, y, e, check_collide(e, ray));
		}
	}
}
