/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 17:01:28 by chuang            #+#    #+#             */
/*   Updated: 2016/02/03 16:07:09 by chuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "libft.h"
#include <math.h>
#include <stdio.h>

#define DISTVUE		1.0
#define LONGV		1.125
#define LARGV		1.5

t_color		check_collision(t_env *e, t_vector ray)
{
	float		inter;
	float		test;
	t_object	*tmp;
//	t_vector	normal;
	t_object	*item;

//APPEL DES LUMIERES	
	tmp = e->scene->l_obj;
	inter = 150.f; //MAX_VISION(e->cam.pos.z);
	//TANT qu'il a des objets test
	while (tmp)// ** TO DO
	{
		if (tmp->type == SPHERE)
		{
			test = inter_sphere(e->cam.pos, ray, *tmp);
//			normal = normal_sphere(e->cam, *item, ray, inter);
		}
		else if(tmp->type == PLANE)
		{
			test = inter_plane(e->cam.pos, ray, *tmp);
//			normal = normal_plane(*item, ray);
		}
		else if (tmp->type == CONE)
		{
			test = inter_cone(e->cam.pos, ray, *tmp);
//			normal = normal_cone(*item, ray, inter, e->cam);
		}
		else
		{
			test = inter_cylinder(e->cam.pos, ray, *tmp);
//			normal = normal_cylinder(*item, ray, inter, e->cam);
		}
//		if(norm_vector(normal) == 0)
//			test = 150.f;
		if (test > 0.01f && test < inter)
		{
			inter = test;
			item = tmp;
		}
		tmp = tmp->next;
	}
	if (inter > 0.0f && inter < 150.f) //&& inter < (float)MAX_VISION(e->cam.pos.z))
	{
		return (diffuse_light(*e->lights, *item,  mult_vector(ray, inter), e));
	}
	return ((t_color){0,0,0});
}

t_vector	ft_posHGV(t_env *e)
{
	t_vector posHGV;

	posHGV = mult_vector(e->cam.dir, DISTVUE);
	posHGV = sub_vector(posHGV, mult_vector(e->cam.h, LONGV / 2));
	posHGV = add_vector(posHGV, mult_vector(e->cam.d, LARGV / 2));
//	posHGV = add_vector(posHGV, e->cam.pos);
	return (posHGV);
}


t_vector	pixel_x_vector(t_env *e, t_vector posHGV, int x)
{
	t_vector	d;
	t_vector	v;

	d = mult_vector(e->cam.d, ((float)(LARGV / (float)SCREEN_W) * (float)x));
	v = sub_vector(mult_vector(posHGV, DISTVUE), d);
	return (v);
}

t_vector	pixel_y_vector(t_env *e, t_vector v_per_x, int y)
{
	t_vector	v;
	t_vector	h;
	
	h = mult_vector(e->cam.h, ((float)(LONGV / (float)SCREEN_H) * (float)y));
	v = add_vector(v_per_x, h);
	return (v);
}


void		ft_render(t_env *e)
{
	t_vector	ray;
	t_vector	posHGV;
	t_vector	v_line_x;
	int			x;
	int			y;
	int			addr;

	e->cam.pos = (t_vector){0., 0., 0.};
	e->cam.h = unit_vector((t_vector){0., 0., -1});
	e->cam.dir = unit_vector((t_vector){1., 0., 0.});
	e->cam.d = cross_vector(e->cam.dir, e->cam.h);
	posHGV = ft_posHGV(e);
	x = 1;
	while (x < SCREEN_W)
	{
		v_line_x = pixel_x_vector(e, posHGV, x);
		y = 1;
		while (y < SCREEN_H)
		{
			ray = pixel_y_vector(e, v_line_x, y);
			ray = unit_vector(ray);
			addr = y * e->mlx_init.img.sizeline + x * e->mlx_init.img.opp;
			put_pixel_to_img(e, addr, check_collision(e, ray));
			y++;
		}
		x++;
	}
}
