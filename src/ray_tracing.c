/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 17:01:28 by chuang            #+#    #+#             */
/*   Updated: 2016/01/12 16:55:48 by chuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define FOV 90

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

	invW = 1 / (float) WINDOW_W;
	invH = 1 / (float) WINDOW_H;
	ratio = WINDOW_W / (float) WIDOW_H;
	angle = tanf(PI *0.5f * FOV/180.);
		y = -1;
	while(++y < WINDOW_H)
	{
		x = -1;
		while (++x < WINDOW_W)
			ray.x = (2 *((x) * invW) - 1) * angle * ratio;
			ray.y = (1 - 2 * ((y) * invH)) * angle;
			ray.z = -1;
			ray = unit_vector(ray);
			r
	}
}
