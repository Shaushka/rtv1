/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   premade_objects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguillon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 11:49:19 by mguillon          #+#    #+#             */
/*   Updated: 2016/02/17 16:57:06 by chuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"
#include <stdlib.h>

static t_object	*set_list_obj_other(void)
{
	t_object	*sphere;
	t_object	*cylind;
	t_object	*cone;

	sphere = malloc(sizeof(t_object));
	cylind = malloc(sizeof(t_object));
	cone = malloc(sizeof(t_object));
	*sphere = set_sphere((t_vector){8, -4, 0}, 1);
	*cylind = set_cylinder((t_vector){-1, 0, 0}, (t_vector){0, 1, 1}, 0.2, -1);
	*cone = set_cone((t_vector){15, 0, 0}, (t_vector){0, 0, 1}, 0.2, -1);
	sphere->color = (t_color){255, 255, 80};
	sphere->shine = 1;
	sphere->reflect = 1;
	cylind->color = (t_color){254, 191, 210};
	cylind->shine = 1;
	cone->color = (t_color){170, 0, 170};
	cone->shine = 1;
	sphere->next = cylind;
	cylind->next = cone;
	cone->next = NULL;
	return (sphere);
}

static t_object	*set_list_obj_planes_part2(void)
{
	t_object	*floor;
	t_object	*backg_w;

	floor = malloc(sizeof(t_object));
	backg_w = malloc(sizeof(t_object));
	*floor = set_plane((t_vector){0, 0, -5}, (t_vector){ 0, 0, 5});
	*backg_w = set_plane((t_vector){30, 0, 0}, (t_vector){ -1, 0, 0});
	floor->color = (t_color){255, 10, 10};
	backg_w->color = (t_color){125, 125, 125};
	floor->checkered = 0;
	backg_w->shine = 0;
	backg_w->reflect = 1;
	floor->next = backg_w;
	backg_w->next = set_list_obj_other();
	return (floor);
}

void			set_list_obj(t_env *e)
{
	t_object	*right_w;
	t_object	*left_w;
	t_object	*roof;

	right_w = malloc(sizeof(t_object));
	left_w = malloc(sizeof(t_object));
	roof = malloc(sizeof(t_object));
	*right_w = set_plane((t_vector){0, -5, 0}, (t_vector){ 0, 5, 0});
	*left_w = set_plane((t_vector){0, 5, 0}, (t_vector){ 0, 5, 0});
	*roof = set_plane((t_vector){0, 0, 5}, (t_vector){ 0, 0, -5});
	right_w->color = (t_color){0, 255, 255};
	left_w->color = (t_color){0, 255, 0};
	roof->color = (t_color){10, 10, 255};
	right_w->reflect = 1;
	right_w->checkered = 0;
	left_w->checkered = 0;
	roof->checkered = 0;
	e->scene->l_obj = right_w;
	right_w->next = left_w;
	left_w->next = roof;
	roof->next = set_list_obj_planes_part2();
}
