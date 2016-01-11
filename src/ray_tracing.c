/ ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 17:01:28 by chuang            #+#    #+#             */
/*   Updated: 2016/01/06 17:43:21 by chuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define FOV 90

t_vect		pxl_vect(int x, int y, env *e)
{
	double		degree;
	t_vect		ray;

	degree = 
	ray.x = d_cos(degree) * x + d_sin(degree) * y;
	ray.y = d_sin(degree) * x + d_cos(degree) * y;
	ray.z = 0; // need to find a formula that work even if your cam wach on Z axis
	return (ray);
}
