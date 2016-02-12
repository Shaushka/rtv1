/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   premade_objects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguillon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 11:49:19 by mguillon          #+#    #+#             */
/*   Updated: 2016/02/12 17:59:16 by chuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"
#include <stdlib.h>

static t_object	*set_list_obj_other(void)
{
	t_object	*sphere;
	t_object	*cylinder;
	t_object	*cone;

	sphere = malloc(sizeof(t_object));
	cylinder = malloc(sizeof(t_object));
	cone = malloc(sizeof(t_object));
	*sphere = set_sphere((t_vector){8, -2, 0}, 1);
	*cylinder = set_cylinder((t_vector){5, 0, 0}, (t_vector){0, 1, 1}, 0.2, -1);
	*cone = set_cone((t_vector){11, 0, 0}, (t_vector){0, 0, 1}, 0.2, -1);
	sphere->color = (t_color){255, 255, 0};
	sphere->shine = 1;
	cylinder->color = (t_color){254, 191, 210};
	cylinder->shine = 1;
	cone->color = (t_color){255, 0, 255};
	cone->shine = 0;
	sphere->next = cylinder;
	cylinder->next = cone;
	cone->next = NULL;
	return (sphere);
}

static t_object	*set_list_obj_planes_part2(void)
{
	t_object	*plane3;
	t_object	*plane4;

	plane3 = malloc(sizeof(t_object));
	plane4 = malloc(sizeof(t_object));
	*plane3 = set_plane((t_vector){0, 0, -5}, (t_vector){ 0, 0, 5});
	*plane4 = set_plane((t_vector){15, 0, 0}, (t_vector){ -1, 0, 0});
	plane3->color = (t_color){255, 0, 0};
	plane4->color = (t_color){255, 255, 255};
	plane3->shine = 0;
	plane4->shine = 0;
	plane3->next = plane4;
	plane4->next = set_list_obj_other();
	return (plane3);
}

void			set_list_obj(t_env *e)
{
	t_object	*plane0;
	t_object	*plane1;
	t_object	*plane2;

	plane0 = malloc(sizeof(t_object));
	plane1 = malloc(sizeof(t_object));
	plane2 = malloc(sizeof(t_object));
	*plane0 = set_plane((t_vector){0, -5, 0}, (t_vector){ 0, 5, 0});
	*plane1 = set_plane((t_vector){0, 5, 0}, (t_vector){ 0, 5, 0});
	*plane2 = set_plane((t_vector){0, 0, 5}, (t_vector){ 0, 0, -5});
	plane0->color = (t_color){0, 255, 255};
	plane1->color = (t_color){0, 255, 0};
	plane2->color = (t_color){0, 0, 255};
	plane0->shine = 0;
	plane1->shine = 0;
	plane2->shine = 1;
	e->scene->l_obj = plane0;
	plane0->next = plane1;
	plane1->next = plane2;
	plane2->next = set_list_obj_planes_part2();
}
