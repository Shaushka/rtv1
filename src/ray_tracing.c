/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 17:01:28 by chuang            #+#    #+#             */
/*   Updated: 2016/02/01 21:38:40 by chuang           ###   ########.fr       */
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
	t_vector	normal;
	t_object	*item;
	t_object	sphere = set_sphere((t_vector){8, 0, 0}, 1);
	t_object	cone = set_cone((t_vector){8, 0, 0},(t_vector){1, 1, 1}, 0.3, 6);
	t_object	cylinder = set_cylinder((t_vector){6, 0, 2},(t_vector){0, 1, 1}, 0.2, 1);
	t_object	plane = set_plane((t_vector){0, -5, 0},(t_vector){ 1, -5, 0});
	t_object	plane1 = set_plane((t_vector){0, 5, 0},(t_vector){ -1, -5, 0});
	t_object	plane2 = set_plane((t_vector){0, 0, 5},(t_vector){ -1, 0, -5});
	t_object	plane3 = set_plane((t_vector){0, 0, -5},(t_vector){ 1, 0, -5});
	t_object	plane4 = set_plane((t_vector){15, 0, 0},(t_vector){ 1, 0, 0});


//APPEL DES LUMIERES	
	item = &plane;
	plane.next = &plane1;
	plane1.next = &plane2;
	plane2.next = &plane3;
	plane3.next = &plane4;
	plane4.next = &sphere;
	sphere.next = &cylinder;
	cylinder.next = &cone;
	cone.next = NULL;
	plane.color = (t_color){0,125,125};
	plane1.color = (t_color){0,125,0};
	plane2.color = (t_color){0,0,125};
	plane3.color = (t_color){125, 0, 0};
	plane4.color = (t_color){125, 125, 125};
	cone.color = (t_color){125,0,125};
	sphere.color = (t_color){125,125,0};
	cylinder.color = (t_color){125, 85, 105};
	inter = 150.f; //MAX_VISION(e->cam.pos.z);
	//TANT qu'il a des objets test
	while (item)// ** TO DO
	{
		if (item->type == SPHERE)
		{
			test = inter_sphere(e->cam, ray, *item);
			normal = normal_sphere(e->cam, *item, ray, inter);
		}
		else if(item->type == PLANE)
		{
			test = inter_plane(e->cam, ray, *item);
			normal = normal_plane(*item, ray);
		}
		else if (item->type == CONE)
		{
			test = inter_cone(e->cam, ray, *item);
			normal = normal_cone(*item, ray, inter, e->cam);
		}
		else
		{
			test = inter_cylinder(e->cam, ray, *item);
			normal = normal_cylinder(*item, ray, inter, e->cam);
		}
		if(norm_vector(normal) == 0)
			test = 150.f;
		if (test > 0.01f && test < inter)
		{
			inter = test;
			tmp = item;
		}
		item = item->next;
	}
	if (inter > 0.0f && inter < 150.f) //&& inter < (float)MAX_VISION(e->cam.pos.z))
	{
		if (tmp->type == SPHERE)
			normal = normal_sphere(e->cam, *tmp, ray, inter);
		else if ( tmp->type == PLANE)
			normal = normal_plane(*tmp, ray); // call assigning normal function
		else if (tmp->type == CONE)
			normal = normal_cone(*tmp, ray, inter, e->cam);
		else
			normal = normal_cylinder(*tmp, ray, inter, e->cam);
		return (diffuse_light(*e->lights, tmp->color, normal, mult_vector(ray, inter)));
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
